#include "shell.h"
/**
* shell_exit - exits the shell
* Return: void
*/
int hshell_exit(void)
{
	return (-1);
}

/**
*shell_env - prints environment
*Return: void
*/
int hshell_env(void)
{
	unsigned int index;
	
	index = 0;
	while (environ[index] != NULL)
	{
		write(STDOUT_FILENO, environ[index], strlen(environ[index]));
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
	return (0);
}
/**
 * count_tokens - count the number of tokens in a
 * NULL-terminated array
 * @tokens: the array of tokens
 *
 * Return: the number of tokens in the array
 */
size_t count_tokens(char **tokens)
{
	size_t count = 0;
	
	if (tokens == NULL || *tokens == NULL)
	{
		printf("Error: tokens not found");
		exit(EXIT_FAILURE);
	}
	while (tokens[count] != NULL)
	{
		count++;
	}
	return (count);
}
