#include "shell.h"

/**
 * main - Entry point for the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt_display();

		read = getline(&line, &len, stdin);
		if (read == -1) /* Ctrl+D */
		{
			free(line);
			exit(0);
		}

		/* Remove trailing newline */
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		if (line[0] != '\0')
			execute_command(line, argv);
	}

	free(line);
	return (0);
}
