#include "main.h"

/**
 * is_interactive - Checks if the shell is running in interactive mode
 * Return: 1 if interactive, 0 otherwise
 */
int is_interactive(void)
{
	return (isatty(STDIN_FILENO));
}

/**
 * get_input_line - Reads a line from standard input
 * @line: Address of the pointer where the line will be stored
 * @len: Size allocated for the line (managed by getline)
 *
 * Return: Number of characters read, or -1 on error or EOF
 */
ssize_t get_input_line(char **line, size_t *len)
{
	ssize_t r;

	r = _getline(line, len, 0);
		if (r == -1)
		{
			if (is_interactive())
				write(1, "\n", 1);
			return (-1);
		}

		if (r > 0 && (*line)[r - 1] == '\n')
			(*line)[r - 1] = '\0';

	return (r);
}

/**
 * handle_builtin_or_execute - Handles execution of built-in commands
 * or external commands found in the PATH.
 * @argv: Array of arguments (command and its parameters)
 * @env: Environment variables (used for locating PATH)
 *
 * Return: -1 if the command is a built-in that requests exit,
 * 0 otherwise.
 */
int handle_builtin_or_execute(char **argv, char **env)
{
	char *cmd_path;

	if (handle_builtin(argv) == -1)
		return (-1);

	cmd_path = _which(argv[0], env);
	if (cmd_path == NULL)
	{
		write(2, "./shell: No such file or directory", 35);
		return (0);
	}

	if (cmd_path != argv[0])
	{
		free(argv[0]);
		argv[0] = cmd_path;
	}

	execute(argv, env);

	return (0);
}

/**
 * shell_loop - Main loop of the shell
 * @env: Environment variables
 *
 * Return: Nothing
 */
void shell_loop(char **env)
{
	char *line = NULL;
	char **argv;
	size_t len = 0;
	ssize_t r;

	while (1)
	{
		if (is_interactive())
			write(1, "cisfun$ ", 9);

		r = get_input_line(&line, &len);
		if (r == -1)
			break;

		argv = stock_args(line);
		if (argv != NULL && argv[0] != NULL)
		{
			if (handle_builtin_or_execute(argv, env) == -1)
			{
				free_argv(argv);
				break;
			}
			free_argv(argv);
		}
	}

	free(line);
}

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
	(void)ac;
	(void)av;

	shell_loop(env);

	return (0);
}
