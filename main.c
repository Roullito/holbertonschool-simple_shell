#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
#define PROMPT "#cisfun$ "

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	int status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1); /* Handle Ctrl+D */
			break;
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		if (line[0] == '\0')
			continue;

		pid = fork();
		if (pid == 0)
		{
			char *argv[2];
			argv[0] = line;
			argv[1] = NULL;

			if (execve(line, argv, environ) == -1)
				perror("./shell_shell");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
			wait(&status);
		else
			perror("fork");
	}

	free(line);
	return (0);
}
