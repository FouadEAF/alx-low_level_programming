#include "main.h"


/**
 * check_elf - Check if a file is an ELF file.
 * @e_Id: A pointer to an array containing the ELF magic numbers.
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_Id)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_Id[index] != 127 &&
		    e_Id[index] != 'E' &&
		    e_Id[index] != 'L' &&
		    e_Id[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * close_elf - Close an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}


/**
 * print_type - Print the type of an ELF header.
 * @e_type: The ELF type.
 * @e_Id: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_Id)
{
	if (e_Id[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Print the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_Id: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_Id)
{
	printf("  Entry point address:               ");

	if (e_Id[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_Id[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * print_data - Print the data of an ELF header.
 * @e_Id: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *e_Id)
{
	printf("  Data:                              ");

	switch (e_Id[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_Id[EI_CLASS]);
	}
}
