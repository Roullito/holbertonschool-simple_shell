#include "main.h"

/**
 * _which - Finds the full path of a command using PATH
 * @filename: Command to search
 * @env: Environment variables
 *
 * Return: Full path (malloc'd) or NULL if not found
 */
char *_which(char *filename, char **env)
{
	char *env_path, *found_path;

	if (filename == NULL || env == NULL)
		return (NULL);

	if (_check_direct_path(filename))
		return (_strdup(filename));

	env_path = _extract_path(env);
	if (!env_path)
		return (NULL);

	found_path = _search_in_path(env_path, filename);
	free(env_path);

	return (found_path);
}

/**
 * _check_direct_path - Verifies if a command is already an executable path
 * @filename: Command name or path
 *
 * Return: 1 if valid executable path, 0 otherwise
 */
int _check_direct_path(char *filename)
{
	if (filename[0] == '/' || filename[0] == '.')
	{
		if (access(filename, X_OK) == 0)
			return (1);
	}
	return (0);
}

/**
 * _extract_path - Extracts and duplicates PATH from env
 * @env: Environment variables
 *
 * Return: malloc'd PATH value (without "PATH="), or NULL
 */
char *_extract_path(char **env)
{
	int i;
	char *copy, *result;

	for (i = 0; env[i]; i++)
	{
		if (_strncmp(env[i], "PATH=", 5) == 0)
		{
			copy = _strdup(env[i]);
			if (!copy)
				return (NULL);
			_strtok(copy, "=");
			result = _strdup(_strtok(NULL, ""));
			free(copy);
			return (result);
		}
	}
	return (NULL);
}

/**
 * _search_in_path - Searches for an executable in directories of PATH
 * @path_str: Duplicated PATH string
 * @filename: Command to look for
 *
 * Return: Full path (malloc'd) or NULL
 */
char *_search_in_path(char *path_str, char *filename)
{
	char *dir, *full_path;
	size_t path_len, file_len;
	char *path_copy;

	if (!path_str || !filename)
		return (NULL);

	path_copy = _strdup(path_str);
	if (!path_copy)
		return (NULL);

	file_len = strlen(filename);
	dir = _strtok(path_copy, ":");

	while (dir != NULL)
	{
		path_len = strlen(dir);
		full_path = malloc(path_len + file_len + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		_strcpy(full_path, dir);
		full_path[path_len] = '/';
		_strcpy(full_path + path_len + 1, filename);
		full_path[path_len + file_len + 1] = '\0';

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = _strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
