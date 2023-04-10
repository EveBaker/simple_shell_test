#include "shell.h"

/**
 * _getenv - gets an environment variable
 * @name: environment variable to get
 * Return: pointer to environment variable or NULL if there is no match
 */

char *_getenv(const char *name)
{
	char **environ_copy;
	char *variable, *value, *path;
	int compare;
	unsigned int length, i;

	environ_copy = copy_env(NULL, _count_env(environ));
	length = _strlen((char *)name);

	for (i = 0; environ_copy[i] != NULL; i++)
	{
		variable = environ_copy[i];
		compare = _strncmp((char *)name, variable, length);
		if (compare == 1)
		{
			value = strtok(variable, "=");
			value = strtok(NULL, "\n ");
			path = _strdup(value);
			free_dp(environ_copy, _count_env(environ));
			return (path);
		}
	}
	return (NULL);
}


/**
 * copy_env - copies environment variable
 * @environ_copy: pointer to copy of environment variable
 * @environ_length: length of environment variable
 * Return: double pointer to copy of environment variable
 */

char **copy_env(char **environ_copy, unsigned int environ_length)
{
	unsigned int i;

	environ_copy = malloc(sizeof(char **) * environ_length);
	if (environ_copy == NULL)
	{
		errors(3);
		return (NULL);
	}

	for (i = 0; i < environ_length; i++)
	{
		environ_copy[i] = _strdup(environ[i]);
		if (environ_copy[i] == NULL)
		{
			errors(3);
			return (NULL);
		}
}

	return (environ_copy);
}
