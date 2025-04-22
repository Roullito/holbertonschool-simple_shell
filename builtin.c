#include "main.h"

/**
 * handle_builtin - Handles built-in shell commands like "exit"
 * @argv: Array of strings containing the command and its arguments
 *
 * Return: -1 if the command is "exit" (to signal termination),
 *         0 otherwise.
 */
int handle_builtin(char **argv)
{
	if (argv[0] && strcmp(argv[0], "exit") == 0)
	{
		if (argv[1])
			exit(atoi(argv[1]));
		return (-1);
	}

	return (0);
}
