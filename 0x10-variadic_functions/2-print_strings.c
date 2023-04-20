#include "variadic_functions.h"

/**
 * print_strings - prints strings.
 * @separator: string to be printed between the strings.
 * @n: number of strings passed to the function.
 * Return: no return.
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list varList;
	char *str;
	unsigned int i;

	va_start(varList, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(varList, char *);

		if (str)
			printf("%s", str);
		else
			printf("(nil)");

		if (i < n - 1)
			if (separator)
				printf("%s", separator);
	}

	printf("\n");
	va_end(varList);
}
