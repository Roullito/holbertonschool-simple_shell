#include "main.h"

/**
* *_memcpy - function that copies memory area.
* @dest: char buffer[98] = {0};
* @src: char buffer2[98] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
* @n: 10
* Return: dest
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
	dest[i] = src[i];
	}

	return (dest);
}
