#include "shell.h"

/**
 * execute_command - Fork and execute a command
 * @command: The command to execute
 * @argv: Program arguments
 */
void execute_command(char *command, char **argv)
{
	pid_t pid;
	int status;
	char *args[2];

	args[0] = command;
	args[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(command, args, environ) == -1)
		{
			print_error(argv[0], command);
			exit(127);
		}
	}
	else
		wait(&status);
}
