#include "shell.h"

/**
 * main - entry point
 *
 * Return: nothing.
 */

int main(void)
{
	char *line;
	char **args;

	while (1)

	{
		line = read_line();
		args = token_line(line);

		if (args && args[0])
		{
			exec_line(args);
		}
		free(line);
		free(args);
	}
}
