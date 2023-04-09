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
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
	return (0);
}
