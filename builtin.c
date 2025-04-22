#include "main.h"

/**
 * is_number - Checks if a string represents a valid integer
 * @str: String to check
 *
 * Return: 1 if the string is a valid number, 0 otherwise
 */
int is_number(const char *str)
{
	int i = 0;

	if (!str)
		return (0);
	if (str[0] == '+' || str[0] == '-')
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
int builtin_exit(char **argv, char **env)
{
	int exit_status = 0;

	(void)env;

	if (argv[1])
	{
		if (!is_number(argv[1]))
		{
			fprintf(stderr, "exit: Illegal number: %s\n", argv[1]);
			return (2);
		}

		exit_status = atoi(argv[1]);
	}

	exit(exit_status);
}

/**
 * builtin_env - Handle the "env" builtin command
 * @argv: Array of command arguments
 * @env: Array of environment variables
 *
 * Return: 1 to indicate the command was handled
 */
int builtin_env(char **argv, char **env)
{
	int i;
	(void)argv;

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
int handle_builtin(char **argv, char **env)
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
			ret = builtins[i].func(argv, env);
			return (ret);
		}
	}

	return (0);
}
