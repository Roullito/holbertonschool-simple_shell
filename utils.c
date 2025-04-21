#include "shell.h"

/**
 * _puts - Prints a string
 * @str: The string to print
 */
void _puts(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}

/**
 * _strlen - Returns the length of a string
 * @s: The string
 *
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * print_error - Prints an error message
 * @name: Name of the shell program (argv[0])
 * @cmd: The command not found
 */
void print_error(char *name, char *cmd)
{
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": 1: ", 5);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
}
