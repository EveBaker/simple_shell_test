#include "shell.h"
/**
  * exec_line - launches and executes processes
  * @args: an argument
  * Return: Always 0
  */
void exec_line(char **args)
{
	int status = 0;
	pid_t child_pid;

	if (args == NULL || *args == NULL)
	{
		return;
	}
	child_pid = fork();
	switch (child_pid)
	{
		case -1:
			perror("hshell");
			exit(1);
			break;
		case 0:
			execvp(args[0], args);
			perror("hshell");
			exit(1);
			break;
		default:
			do {
				if (waitpid(child_pid, &status, WUNTRACED) == -1)
				{
					if (errno == EINTR)
					{
					continue;
					}
					perror("hshell");
					exit(1);
				}
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			break;
	}
}
