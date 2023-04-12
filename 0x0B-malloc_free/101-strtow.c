#include <stdlib.h>
#include "main.h"

/**
 * ch_free_grid - frees a 2 dimensional array.
 * @grid: multidimensional array of char.
 * @h: h of the array.
 * Return: no return.
 */

void ch_free_grid(char **grid, unsigned int h)
{
	if (grid != NULL && h != 0)
	{
		for (; h > 0; h--)
			free(grid[h]);
		free(grid[h]);
		free(grid);
	}
}

/**
 * strtow - splits a string into words.
 * @str: string.
 * Return: pointer of an array of integers.
 */

char **strtow(char *str)
{
	char **stout;
	unsigned int c, h, i, j, b;

	if (str == NULL || *str == '\0')
		return (NULL);
	for (c = h = 0; str[c] != '\0'; c++)
		if (str[c] != ' ' && (str[c + 1] == ' ' || str[c + 1] == '\0'))
			h++;
	stout = malloc((h + 1) * sizeof(char *));
	if (stout == NULL || h == 0)
	{
		free(stout);
		return (NULL);
	}
	for (i = b = 0; i < h; i++)
	{
		for (c = b; str[c] != '\0'; c++)
		{
			if (str[c] == ' ')
				b++;
			if (str[c] != ' ' && (str[c + 1] == ' ' || str[c + 1] == '\0'))
			{
				stout[i] = malloc((c - b + 2) * sizeof(char));
				if (stout[i] == NULL)
				{
					ch_free_grid(stout, i);
					return (NULL);
				}
				break;
			}
		}
		for (j = 0; b <= c; b++, j++)
			stout[i][j] = str[b];
		stout[i][j] = '\0';
	}
	stout[i] = NULL;
	return (stout);
}
