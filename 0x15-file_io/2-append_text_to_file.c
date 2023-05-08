#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: filename.
 * @text_content: added content.
 * Return: 1 if the file exists. -1 if the fails does not exist or if it fails.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int myFile;
	int nbrLetters;
	int rdwr;

	if (!filename)
		return (-1);

	myFile = open(filename, O_WRONLY | O_APPEND);

	if (myFile == -1)
		return (-1);

	if (text_content)
	{
		for (nbrLetters = 0; text_content[nbrLetters]; nbrLetters++)
			;

		rdwr = write(myFile, text_content, nbrLetters);

		if (rdwr == -1)
			return (-1);
	}

	close(myFile);

	return (1);
}
