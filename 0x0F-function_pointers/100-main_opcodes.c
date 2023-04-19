#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code for ALX school students.
 * @argc: argument count.
 * @argv: argument vector.
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	char *opcode = (char *) main;
	int i, nbrBytes;

	if (argc != 2)
	{
  		printf("Error\n");
  		exit(1);
	}

	nbrBytes = atoi(argv[1]);

	if (nbrBytes < 0)
	{
	  	printf("Error\n");
	  	exit(2);
	}
	
	for(i = 0; i < nbrBytes; i++)
	{
	  	printf("%02x", opcode[i] & 0xFF);
	  	if (i != nbrBytes - 1)
			printf(" ");
	}
	
	printf("\n");
	return (0);
}
