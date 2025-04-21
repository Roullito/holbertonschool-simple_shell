#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "

int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	int status;

	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
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

			if (execve(line, argv, NULL) == -1)
				perror(av[0]);
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
