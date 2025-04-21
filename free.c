#include "main.h"

/**
 * free_argv - Frees a NULL-terminated array of strings
 * @argv: The array of strings to free
 *
 * Return: Nothing
 */
void free_argv(char **argv)
{
	int i;

	if (!argv)
		return;

	for (i = 0; argv[i]; i++)
		free(argv[i]);

	free(argv);
}
