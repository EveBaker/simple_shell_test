#include "shell.h"

/**
 * main - entry point
 *
 * Return: nothing.
 */

int main(void)
{
	char *line;
	char **tokens;

	while (true)

	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		line = shell_readline();
		tokens = shell_splitline(line);

		if (tokens[0] != NULL)
		{
			shell_exec(tokens);
		}
		free(tokens);
		free(line);

	}
}
