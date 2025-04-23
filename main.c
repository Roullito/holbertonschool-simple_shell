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

	if (!line || !len)
		return (-1);
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
 * @progname: Name of the program (for error messages)
 *
 * Return: -1 if the command is a built-in that requests exit,
 * 0 otherwise.
*/
int handle_builtin_or_execute(char **argv, char **env, char *progname,
	char *line)
{
	char *cmd_path;
	int exec_status;

	if (!argv || !argv[0] || !env || !progname)
		return (0);

	if (handle_builtin(argv, env, line) == -1)
		return (-1);

	cmd_path = _which(argv[0], env);
	if (cmd_path == NULL)
	{
		fprintf(stderr, "%s: command '%s' not found\n", progname, argv[0]);
		return (127);
	}

	if (cmd_path != argv[0])
	{
		free(argv[0]);
		argv[0] = cmd_path;
	}

	exec_status = execute(argv, env);
	return (exec_status);
}
/**
 * shell_loop - Main loop of the shell
 * @env: Environment variables
 * @progname: Name of the program (for error messages)
 *
 * Return: Nothing
*/
int shell_loop(char **env, char *progname, int *exit_status)
{
	char *line = NULL;
	char **argv = NULL;
	size_t len = 0;
	ssize_t r;
	int cmd_status;

	while (1)
	{
		if (is_interactive())
			write(1, "#cisfun$ ", 9);
		r = get_input_line(&line, &len);
		if (r == -1)
			break;
		if (r == 0 || line[0] == '\0')
			continue;
		argv = stock_args(line);
		if (argv != NULL && argv[0] != NULL)
		{
			cmd_status = handle_builtin_or_execute(argv, env, progname, line);
			*exit_status = cmd_status;
			if (cmd_status == -1)
			{
				free_argv(argv);
				break;
			}
			free_argv(argv);
		}
		else if (argv != NULL)
		{
			free_argv(argv);
		}
	}
	if (line)
		free(line);

	return (0);
}

/**
 * main - Entry point of our custom shell
 * @ac: Argument count (unused)
 * @av: Argument vector
 * @env: Environment variables
 *
 * Return: Exit status of the shell
*/
int main(int ac, char **av, char **env)
{
	int exit_status = 0;

	(void)ac;
	if (shell_loop(env, av[0], &exit_status) == -1)
		return (exit_status);

	return (exit_status);
}
