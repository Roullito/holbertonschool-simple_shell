#include "main.h"

/**
 * execute - Creates a child process to execute a command
 * @argv: Array of strings representing the command and its arguments
 * @env: Environment variables
 *
 * Return: 0 on success, 1 on failure
 */
int execute(char **argv, char **env)
{
	int status;
	pid_t pid;
	pid_t my_pid;

	if (argv == NULL || argv[0] == NULL)
		return (1);

	my_pid = getppid();
	printf("PPID: %d\n", my_pid);

	pid = fork();
	if (pid == -1)
	{
		perror("Error: fork");
		return (1);
	}

	if (pid == 0)
	{
		my_pid = getpid();
		printf("PID: %d\n", my_pid);

		if (execve(argv[0], argv, env) == -1)
		{
			perror("Error: execve");
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		wait(&status);
	}

	return (0);
}
