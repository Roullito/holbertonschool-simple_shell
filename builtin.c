#include "main.h"

/**
 * _is_number - Check if a string is a valid integer number
 * @str: String to check
 *
 * Return: 1 if numeric, 0 otherwise
 */
int _is_number(char *str)
{
	int i = 0;
	if (!str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	for (; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * builtin_exit - Handle the "exit" builtin command
 * @argv: Array of command arguments
 * @env: Array of environment variables
 *
 * Return: -1 to indicate shell termination
 */
int builtin_exit(char **argv, char **env, char *line)
{
	int exit_status = 0;

	(void)env;

	if (argv[1])
	{
		if (_is_number(argv[1]))
			exit_status = atoi(argv[1]);

		else
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", argv[1]);
			free_argv(argv);
			free(line);
			exit(2);
		}
	}

	free_argv(argv);
	free(line);
	exit(exit_status);
}

/**
 * builtin_env - Handle the "env" builtin command
 * @argv: Array of command arguments
 * @env: Array of environment variables
 *
 * Return: 1 to indicate the command was handled
 */
int builtin_env(char **argv, char **env, char *line)
{
	int i;

	(void)line;

	if (argv[1])
		return (0);

	if (!env)
		return (1);

	for (i = 0; env[i]; i++)
		printf("%s\n", env[i]);

	return (0);
}

/**
 * handle_builtin - Check and execute builtin shell commands
 * @argv: Array of command arguments
 * @env: Array of environment variables
 *
 * Return: -1 if "exit", 1 if a builtin was handled, 0 otherwise
 */
int handle_builtin(char **argv, char **env, char *line)
{
	int i, ret;

	builtin_t builtins[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{NULL, NULL}
	};

	if (!argv || !argv[0])
		return (0);

	for (i = 0; builtins[i].name; i++)
	{
		if (strcmp(argv[0], builtins[i].name) == 0)
		{
			ret = builtins[i].func(argv, env, line);
			return (ret);
		}
	}

	return (0);
}
