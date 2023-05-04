#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: binary.
 * Return: unsigned int.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int ui;
	int lenght, Bz2;

	if (!b)
		return (0);

	ui = 0;

	for (lenght = 0; b[lenght] != '\0'; lenght++)
		;

	for (lenght--, Bz2 = 1; lenght >= 0; lenght--, Bz2 *= 2)
	{
		if (b[lenght] != '0' && b[lenght] != '1')
		{
			return (0);
		}

		if (b[lenght] & 1)
		{
			ui += Bz2;
		}
	}

	return (ui);
}
