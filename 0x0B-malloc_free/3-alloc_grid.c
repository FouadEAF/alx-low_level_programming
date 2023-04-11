#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: width of the array.
 * @height: height of the array.
 * Return: pointer of an array of integers
 */

int **alloc_grid(int width, int height)
{
	int **gdout;
	int i, j;

	if (width < 1 || height < 1)
		return (NULL);

	gdout = malloc(height * sizeof(int *));
	if (gdout == NULL)
	{
		free(gdout);
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		gdout[i] = malloc(width * sizeof(int));
		if (gdout[i] == NULL)
		{
			for (i--; i >= 0; i--)
				free(gdout[i]);
			free(gdout);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			gdout[i][j] = 0;

	return (gdout);
}
