#include "dog.h"
#include <stdio.h>

/**
 * print_dog - prints a struct dog.
 * @dg: struct dog.
 *
 * Return: no return.
 */

void print_dog(struct dog *dg)
{
	if (dg)
	{
		if (!(dg->name))
			printf("Name: (nil)\n");
		else
			printf("Name: %s\n", dg->name);

		printf("Age: %f\n", dg->age);

		if (!(dg->owner))
			printf("Owner: (nil)\n");
		else
			printf("Owner: %s\n", dg->owner);
	}
}
