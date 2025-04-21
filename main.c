#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "

/**
 * main - Minimal shell for exercise 0 (no PATH, no builtins)
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	int status;

	while (1)
	{
		write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			write(STDOUT_FILENO, "\n", 1); /* Handle Ctrl+D */
			break;
		}

		/* Remove newline */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		pid = fork();
		if (pid == 0) /* Child */
		{
			char *argv[2];
			argv[0] = line;
			argv[1] = NULL;

			if (execve(line, argv, NULL) == -1)
				perror("./shell");
			exit(1);
		}
		else if (pid > 0) /* Parent */
			wait(&status);
		else
			perror("fork");
	}

	return (0);
}
