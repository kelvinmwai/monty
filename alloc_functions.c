#include "monty.h"

/**
 * _calloc - concatenate two strings to a memory block
 * @n: number of elements
 * @size: type of elements
 * Return: nothing
 */
void *_calloc(unsigned int n, unsigned int size)
{
	void *v = NULL;
	unsigned int x;

	if (n == 0 || size == 0)
	{
		return (NULL);
	}
	v = malloc(n * size);
	if (v == NULL)
	{
		return (NULL);
	}
	for (x = 0; x < (n * size); x++)
	{
		*((char *)(v) + x) = 0;
	}
	return (v);
}
/**
 * _realloc - change the size of block transfer content
 * @pnt: pointer to malloc for reallocation
 * @old_size: old number of bytes
 * @new_size: new number of Bytes
 * Return: nothing
 */
void *_realloc(void *pnt, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int y;

	if (new_size == old_size)
		return (pnt);
	if (pnt == NULL)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_size == 0 && pnt != NULL)
	{
		free(pnt);
		return (NULL);
	}
	if (new_size > old_size)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (y = 0; y < old_size; y++)
			p[y] = *((char *)pnt + y);
		free(pnt);
	}
	else
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (y = 0; y < new_size; y++)
			p[y] = *((char *)pnt + y);
		free(pnt);
	}
	return (p);
}
