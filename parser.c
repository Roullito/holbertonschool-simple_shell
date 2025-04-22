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

/**
 * stock_args - Tokenizes a line into arguments
 *
 * @line: Pointer to the input line to split
 * Return: A pointer to the array of token strings (argv), or NULL on failure
 */
char **stock_args(char *line)
{
	int count = 0, i = 0;
	char *cp_line, *cp_line2, *token, **argv;

	if (line == NULL)
		return (NULL);
	cp_line = _strdup(line);
	if (cp_line == NULL)
		return (NULL);
	token = _strtok(cp_line, " ");
	while (token != NULL)
	{
		count++;
		token = _strtok(NULL, " "); }
	argv = malloc(sizeof(char *) * (count + 1));
	if (argv == NULL)
	{
		free(cp_line);
		return (NULL); }
	free(cp_line);
	cp_line2 = _strdup(line);
	if (cp_line2 == NULL)
	{
		free(argv);
		return (NULL); }
	token = _strtok(cp_line2, " ");
	while (token != NULL && i < count)
	{
		argv[i] = _strdup(token);
		if (argv[i] == NULL)
		{
			while (--i >= 0)
				free(argv[i]);
			free(argv);
			free(cp_line2);
			return (NULL); }
		i++;
		token = _strtok(NULL, " "); }
	argv[i] = NULL;
	free(cp_line2);
	return (argv);
}
