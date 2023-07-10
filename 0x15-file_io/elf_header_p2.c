#include "main.h"

/**
 * print_magic - Print the magic numbers of an ELF header.
 * @e_Id: A pointer to an array containing the ELF magic numbers.
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_Id)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_Id[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Print the class of an ELF header.
 * @e_Id: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *e_Id)
{
	printf("  Class:                             ");

	switch (e_Id[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_Id[EI_CLASS]);
	}
}

/**
 * print_version - Print the version of an ELF header.
 * @e_Id: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *e_Id)
{
	printf("  Version:                           %d",
	       e_Id[EI_VERSION]);

	switch (e_Id[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Print the OS/ABI of an ELF header.
 * @e_Id: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_Id)
{
	printf("  OS/ABI:                            ");

	switch (e_Id[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_Id[EI_OSABI]);
	}
}

/**
 * print_abi - Print the ABI version of an ELF header.
 * @e_Id: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_Id)
{
	printf("  ABI Version:                       %d\n",
	       e_Id[EI_ABIVERSION]);
}
