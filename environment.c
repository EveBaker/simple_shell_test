#include "shell.h"

/**
 * _getenv - get env variables
 * @env_var: env variable
 * Return: env variable result, its content
 */

char *_getenv(char *env_var)
{
	int env_var_indx = 0;
	size_t len;
	char *value;

	if (!env_var)
	{
		perror("_getenv: invalid");
		return (NULL);
	}
	len = _strlen(env_var);

	while (environ[env_var_indx])
	{
		if (_strncmp(env_var, environ[env_var_indx], len) == 0)
		{
			if (environ[env_var_indx][len] == '=')
			{
				value = environ[env_var_indx] + len + 1;
				return (value);
			}
			env_var_indx++;
		}
	}

	perror("_getenv: environment variable not found");
	return (NULL);
}


/**
  * _env - prints environment
  */
void _env(void)
{
	int env_var_indx = 0;
	size_t env_var_len = 0;

	while (environ[env_var_indx])
	{
		env_var_len = _strlen(environ[env_var_indx]);
		if (write(STDOUT_FILENO, environ[env_var_indx], env_var_len) < 0)
		{
			perror("_env: error printing environment");
			return;
		}
		if (write(STDOUT_FILENO, "\n", 1) < 0)
		{
			perror("_env: error writing to standard output");
			return;
		}
		env_var_indx++;
	}
}
#include "main.h"

/**
 * execute - execute command path, child process
 * @args: arguments
 * Return: exit status
 */
int execute(char **args)
{
	int pid = 0, status = 0;

	if (args == NULL || args[0] == NULL)
	{
		perror("Error: invalid arguments");
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error: fork failed");
		return (-1); }
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("Error, execve failed");
			exit(1);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Error: waitpid failed");
			return (1);
		}
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
	}
	return (status);
}

/**
 * get_input - Reads a line of input from
 * stdin and returns it as a string
 * Return: A pointer to the input string,
 * or NULL if an error occurs
 */
char *get_input(void)
{
	char input[100];
	char *buffer = NULL;
	size_t input_len = 0;

	if (fgets(input, sizeof(input), stdin) == NULL)
	{
		perror("Error reading input");
		return (NULL);
	}
	input_len = strlen(input);
	/*Check for newline at end of input*/
	if (input_len > 0 && input[input_len - 1] == '\n')
	{
		input[input_len - 1] = '\0';
		/*Remove newline*/
		input_len--;
	}
	buffer = malloc(input_len + 1);
	if (buffer == NULL)
	{
		perror("Error allocating memory for input");
		return (NULL);
	}
	_strcpy(buffer, input);
	return (buffer);
}
