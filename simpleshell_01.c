#include "shell.h"

#define MAX_COMMAND_LEN 100
/**
  * simple_shell - cli to execute user commands
  * Return: void, Always 0
  */
void simple_shell(void)
{
	char command[MAX_COMMAND_LEN + 1];
	int status;

	while (1)
	{
		printf("$ ");
		if (fgets(command, MAX_COMMAND_LEN, stdin) == NULL)
		{/*Exit on end-of-file condition*/
			exit(0);
		}
		if (command[strlen(command) - 1] == '\n')
		{/*Remove trailing newline*/
			command[strlen(command) - 1] = '\0';
		}
		if (strlen(command) == 0)
		{/*Ignore empty lines*/
			continue;
		}
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{/*Child process*/
			execlp(command, command, NULL);
			/*If execlp returns, there was an error*/
			perror(command);
			exit(1);
		}
		else
		{/*Parent process*/
			wait(&status);
		}
	}
}
