#include "main.h"

/**
 * main - Entry point of our custom shell
 * @ac: Argument count (unused)
 * @av: Argument vector (unused)
 * @env: Environment variables
 *
 * Return: Always 0
 */
int main(int ac, char **av, char **env)
{
	char **argv, *line = NULL, *cmd_path;
	size_t len = 0;
	ssize_t r;
	int i;

	(void)ac;
	(void)av;

	while (1)
	{
		write(1, "$ ", 2);

		r = _getline(&line, &len, 0);
		if (r == -1)
		{
			write(1, "\n", 1);
			break;
		}

		if (r > 0 && line[r - 1] == '\n')
			line[r - 1] = '\0';

		argv = stock_args(line);
		if (argv != NULL && argv[0] != NULL)
		{
			if (handle_builtin(argv) == -1)
				break;
			cmd_path = _which(argv[0], env);
			if (cmd_path == NULL)
			{
				write(2, "Command not found\n", 19);
			}
			else
			{
				if (cmd_path != argv[0])
				{
					free(argv[0]);
					argv[0] = cmd_path;
				}
				execute(argv, env);
			}

			for (i = 0; argv[i]; i++)
				free(argv[i]);
			free(argv);
		}
	}

	free(line);
	return (0);
}
