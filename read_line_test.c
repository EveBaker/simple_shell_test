#include "shell.h"
/**
  * main - tests readline
  * Return: int
  */
int main(void)
{
	char *line;

	line = read_line();
	printf("You entered: %s\n", line);
	free(line);
	return (0);
}
