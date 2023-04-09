#include "shell.h"
/**
  * main - hshell main function implement simple shell
  * @argc: arg count 
  * @argv: arg vector
  * Return: Always 0
  */
#define MAX_COMMAND_LEN 100

int main(int argc, char *argv[])
{
	char command[MAX_COMMAND_LEN + 1];
	int status;
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t bytes_read;
	
	if (argc == 1)
	{/*Interactive mode: read commands from the command line*/
		while (1)
		{
			printf("$ ");
			if (fgets(command, MAX_COMMAND_LEN, stdin) == NULL)
			{/*Exit on end-of-file condition*/
				exit(0);
			}
			if (command[strlen(command) - 1] == '\n')
			{
				/*Remove trailing newline*/
				command[strlen(command) - 1] = '\0';
			}
			if (strlen(command) == 0)
			{/*Ignore empty lines*/
				continue;
			}
			exec_line(command);
		}
	}
	else
	{
        /*Non-interactive mode: read commands from standard input*/
		while ((bytes_read = getline(&command, &bufsize, stdin)) != -1)
		{
			if (bytes_read > 0 && command[bytes_read - 1] == '\n')
			{/*Remove trailing newline*/
				command[bytes_read - 1] = '\0';
			}
			exec_line(command);
		}
		free(command);
		exit(0);
	}
	return 0;
}
