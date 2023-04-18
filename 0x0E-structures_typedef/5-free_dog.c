#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees dogs.
 * @dg: struct dog.
 *
 * Return: no return.
 */

void free_dog(dog_t *dg)
{
	if (dg)
	{
		free(dg->name);
		free(dg->owner);
		free(dg);
	}
}
