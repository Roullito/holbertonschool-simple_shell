#include "main.h"

/**
 * _strncmp - Compares up to n characters of two strings
 * @s1: First string
 * @s2: Second string
 * @n: Maximum number of characters to compare
 *
 * Return: 0 if equal, negative if s1 < s2, positive if s1 > s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && (s1[i] != '\0' || s2[i] != '\0'); i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (0);
}
