#include "shell.h"
/**
 * exec_builtin_cmds - executes a builtin command
 * @user_args: array of user tokens
 * Return: 1 if there's a builtin command, otherwise 0
 */

int exec_builtin_cmds(char **user_args)
{
	int i = 0;
	char *list_builtin_cmds[] = {"exit", "env", NULL};

	while (list_builtin_cmds[i])
	{
		if (strcmp(user_tokens[0], list_builtin_cmds[i]) == 0)
		{
			switch (i)
			{
				case 0:
					exit_shell();
				case 1:
					_print_env();
					return (1);
				default:
					break;
			}
		}
		i++;
	}
	return (0);
}
