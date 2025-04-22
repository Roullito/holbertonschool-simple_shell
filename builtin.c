#include "main.h"

/**
 * handle_builtin - Handles built-in shell commands like "exit" and "env"
 * @argv: Array of strings containing the command and its arguments
 * @env: Array of environment variables
 *
 * Return: -1 if the command is "exit" (to signal termination),
 *          1 if the command is "env" (command handled),
 *          0 otherwise (not a builtin command).
 */
int handle_builtin(char **argv, char **env)
{
	int i;

	if (!argv || !argv[0])
		return (0);

	if (strcmp(argv[0], "exit") == 0)
	{
		return (-1);
	}
	else if (strcmp(argv[0], "env") == 0)
	{
		for (i = 0; env[i]; i++)
			printf("%s\n", env[i]);
		return (1);
	}

	return (0);
}
