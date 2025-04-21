#include "main.h"

/**
 * _which - Finds the full path of a command using
 * the PATH environment variable
 * @filename: Name of the command (e.g. "ls")
 * @env: Environment variables
 *
 * Return: Pointer to allocated string containing full path,
 * or NULL if not found
 */
char *_which(char *filename, char **env)
{
	size_t i;
	struct stat st;
	char *path, *full_path, *env_path;

	if (filename[0] == '/')
	{
		if (stat(filename, &st) == 0)
			return (_strdup(filename));
		else
			return (NULL); }
	for (i = 0; env[i]; i++)
	{
		if (_strncmp(env[i], "PATH=", 5) == 0)
		{
			env_path = _strdup(env[i]);
			if (env_path == NULL)
				return (NULL);
			_strtok(env_path, "=");
			path = _strtok(NULL, ":");
			while (path != NULL)
			{
				full_path = malloc(1024);
				if (full_path == NULL)
				{
					free(env_path);
					return (NULL);
				}
				sprintf(full_path, "%s/%s", path, filename);
				if (stat(full_path, &st) == 0)
				{
					free(env_path);
					return (full_path);
				}
				free(full_path);
				path = _strtok(NULL, ":");
			}
			free(env_path);
		}
	}
	return (NULL);
}
