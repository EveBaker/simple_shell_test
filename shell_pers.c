#include "shell.h"
/**
  * print_prompt -function that prompts user cli
  * return: Always 0
  */
void print_prompt(void)
{
	size_t len = write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

	if (len == -1)
	{
		perror("Error: failed to write to prompt");
		exit(EXIT_FAILURE);
	}
}
