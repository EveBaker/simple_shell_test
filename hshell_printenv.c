#include "shell.h"
/**
* print_env - prints the environment built-ins
* Return: Always 0
*/
int print_env(void)
{
	char **env = eviron;

	while (*env != NUll)
	{
		printf(%s\n, *env);
		env++;
	}
	return (0);
}
