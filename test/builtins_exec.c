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

	if (user_args == NULL || user_args[0] == NULL)
	{
		return (0);
	}
	while (list_builtin_cmds[i])
	{
		if (strcasecmp(user_args[0], list_builtin_cmds[i]) == 0)
		{
			switch (i)
			{
				case 0:
					exit_shell();
					break;
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
