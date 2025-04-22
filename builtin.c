#include "main.h"

/**
 * builtin_exit - Handle the "exit" builtin command
 * @argv: Array of command arguments
 * @env: Array of environment variables
 *
 * Return: -1 to indicate shell termination
 */
int builtin_exit(char **argv, char **env)
{
	(void)argv;
	(void)env;
	return (-1);
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
	return (1);
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
	int i;
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
			return (builtins[i].func(argv, env));
	}
	return (0);
}
