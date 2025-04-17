#include "main.h"

/**
 * is_delim - Checks if a character is one of the delimiters
 * @c: The character to check
 * @delim: The string of delimiter characters
 *
 * Return: 1 if c is a delimiter, 0 otherwise
 */
int is_delim(char c, const char *delim)
{
	while (*delim != '\0')
	{
		if (*delim == c)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _strtok - Custom implementation of strtok to tokenize a string
 * @str: The input string to tokenize (only on first call)
 * @delim: The delimiter characters used to split the string
 *
 * Return: A pointer to the next token, or NULL if no more tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *current;
	char *token;

	if (str != NULL)
	{
		current = str;
	}

	while (*current != '\0' && is_delim(*current, delim))
	{
		current++;
	}

	if (*current == '\0')
		return (NULL);

	token = current;

	while (*current != '\0' && !is_delim(*current, delim))
		current++;

	if (*current != '\0')
	{
		*current = '\0';
		current++;
	}

	return (token);
}

char **stock_args(char *line)
{
	int count = 0, i = 0;
	char *cp_line, *cp_line2, *token, **argv;

	cp_line = _strdup(line);
	token = _strtok(cp_line, " ");

	while (token != NULL)
	{
		count++;
		token = _strtok(NULL, " ");
	}

	argv = malloc(sizeof(char *) * (count + 1));
	if (argv == NULL)
		return (NULL);

	free(cp_line);

	cp_line2 = _strdup(line);
	token = _strtok(cp_line2, " ");
	while (token != NULL)
	{
		argv[i] = _strdup(token);
		if (argv[i] == NULL)
			return (NULL);

		i++;
		token = _strtok(NULL, " ");
	}

	argv[i] = NULL;
	free(cp_line2);
	return (argv);
}
