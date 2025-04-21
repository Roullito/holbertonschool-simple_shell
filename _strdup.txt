#include "main.h"

/**
 * _strdup - Creates a duplicate of a string in newly allocated memory
 * @str: The string to duplicate
 *
 * Return: Pointer to the duplicated string, or NULL on failure
 */
char *_strdup(char *str)
{
	int i;
	char *copy_str;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;

	copy_str = malloc((i + 1) * sizeof(char));
	if (copy_str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		copy_str[i] = str[i];

	copy_str[i] = '\0';
	return (copy_str);
}
