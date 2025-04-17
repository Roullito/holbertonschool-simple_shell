#include "main.h"

/**
 * char *_strcpy - function that copies the string pointed to by src
 *
 * @src: pointe vers la chaîne originale.
 * @dest: pointe vers s1, qui est le tableau où la copie est stockée.
 *
 * Return: dest.
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
