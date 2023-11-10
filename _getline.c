#include "shell.h"

/**
 *main-Entry point of the program.
 *getline:Read The Input By User from Read
 *
 * Return: Success (0)
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		if (line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
			read--;
		}
/**
 * hash_handler - Handle hash character in input
 * @buff: input buffer
 */
void hash_handler(char *buff)
{
	int i = 0;

	while (buff[i] != '\0')
	{
		if (buff[i] == '#')
			buff[i] = '\0';
		i++;
	}
}
