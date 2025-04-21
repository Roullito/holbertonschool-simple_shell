#include "main.h"
/**
 * _getline - Reads a line from a file descriptor (stdin by default)
 *            character by character and stores it into a dynamically
 *            allocated buffer, reallocating if necessary.
 *
 * @lineptr: Pointer to the buffer that will contain the line
 * @n: Pointer to the size of the buffer
 * @fd: File descriptor to read from (e.g., 0 for stdin)
 *
 * Return: Number of characters read (excluding null byte),
 *         -1 on failure or EOF.
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	size_t i = 0, new_size;
	char *temp, c;
	ssize_t r;

	if (lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while (1)
	{
		r = read(fd, &c, 1);
		if (r < 0)
			return (-1);
		if (r == 0)
			return (-1);

		if (i >= (*n - 1))
		{
			new_size = ((*n) * 2);
			temp = malloc(new_size);
			if (temp == NULL)
				return (-1);

			_memcpy(temp, *lineptr, *n);
			free(*lineptr);
			*lineptr = temp;
			*n = new_size;
		}
		(*lineptr)[i++] = c;
		if (c == '\n')
			break;
	}
	(*lineptr)[i] = '\0';
	return (i);
}
