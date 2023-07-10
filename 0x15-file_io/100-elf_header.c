#include "main.h"
#include <elf.h>

/**
 * main - Display the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointer to the argument.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_Id);
	printf("ELF Header:\n");
	print_magic(header->e_Id);
	print_class(header->e_Id);
	print_data(header->e_Id);
	print_version(header->e_Id);
	print_osabi(header->e_Id);
	print_abi(header->e_Id);
	print_type(header->e_type, header->e_Id);
	print_entry(header->e_entry, header->e_Id);

	free(header);
	close_elf(o);
	return (0);
}
