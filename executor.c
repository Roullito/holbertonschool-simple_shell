#include "main.h"
/**
 * execute - Creates a child process to execute a command
 * @argv: Array of strings representing the command and its arguments
 * @env: Environment variables
 *
 * Return: the exit status of the child process, or 1 on fork error
 */
int execute(char **argv, char **env)
{
	int status;
	pid_t pid;
	if (argv == NULL || argv[0] == NULL)
		return (1);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror("execve");
			exit(127);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
			return (1);
	}
	return (0);
}
