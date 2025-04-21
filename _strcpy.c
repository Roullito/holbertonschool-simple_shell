#include "main.h"

/**
 * _strcpy - Copies the string pointed to by src into dest
 * @src: Pointer to the source string
 * @dest: Pointer to the destination buffer where the string will be copied
 *
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';

	return (dest);
}
