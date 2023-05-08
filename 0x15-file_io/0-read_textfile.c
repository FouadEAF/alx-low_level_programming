#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters.
 * @filename: filename.
 * @letters: numbers of letters printed.
 * Return: numbers of letters printed. It fails, returns 0.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	ssize_t Ird, Iwr;
	char *buff;

	if (!filename)
		return (0);

	file = open(filename, O_RDONLY);

	if (file == -1)
		return (0);

	buff = malloc(sizeof(char) * (letters));
	if (!buff)
		return (0);

	Ird = read(file, buff, letters);
	Iwr = write(STDOUT_FILENO, buff, Ird);

	close(file);

	free(buff);

	return (Iwr);
}
