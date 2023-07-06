#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b : binary.
 * Return: the converted number, or 0 if
 * there is one or more chars in the string b that is not 0 or 1, b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int u;
	int leng, i;

	if (!b)
		return (0);

	u = 0;

	for (leng = 0; b[leng] != '\0'; leng++)
		;

	for (leng--, i = 1; leng >= 0; leng--, i *= 2)
	{
		if (b[leng] != '0' && b[leng] != '1')
		{
			return (0);
		}

		if (b[leng] & 1)
		{
			u += i;
		}
	}

	return (u);
}
