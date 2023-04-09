#include "shell.h"
/**
  * read_line - function that prints $ and waits for command
  * Return: 0 is success
  */


char *read_line(void)
{
	char *line = NULL;
	ssize_t len = 0;
	size_t	size = 0;

	printf("$ ");
	/*getline reads user input*/
	len = getline(&line, &size, stdin);
	/*if user enters nothing getline returns -1*/
	if (len != -1)
	{
	/*if user enters command*/
		printf("%s", line);
		if (line != NULL)
		{
		/*getline allocates memory*/
		free(line);
		line = NULL;
		}
	}
	return (line);
}
