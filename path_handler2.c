#include "main.h"
/**
 * check_path_command - checks if the command is
 * an absolute or relative path
 * @command: the command to search for
 * Return: the path to the command, or NULL if not found
 */
char *check_path_command(char *command)
{
	char *path_cmd = NULL, *input = NULL;

	if (!command)
	{
		perror("check_path_command: invalid input");
		return (NULL);
	}
	input = get_input();
	if (!input)
	{
		perror("check_path_command: failed to read input");
		return (NULL);
	}
	if (_strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
		{
			path_cmd = _strcpy(malloc(_strlen(input) + 1), input);
			if (!path_cmd)
			{
				perror("check_path_command: malloc failed");
				free(input);
				return (NULL);
			}
			free(input);
			return (path_cmd);
		}
		else
		{	free(input);
			return (NULL); }
	}
	path_cmd = search_path(command);
	if (!path_cmd)
	{
		perror("check_path_command: cmnd not found");
		free(input);
		return (NULL);
	}
	free(input);
	return (path_cmd);
}

/**
 * search_path_command - searches for a command
 * within a single directory
 * @dir: the directory to search
 * @command: the command to search for
 * Return: the path to the command, or NULL if not found
 */
char *search_path_command(char *dir, char *command)
{
	char *path = NULL;
	int dir_len = _strlen(dir);
	int cmd_len = _strlen(command);

	if (!dir || !command)
	{
		perror("search_path_command: invalid input");
		return (NULL);
	}
	path = malloc(dir_len + cmd_len + 2);
	if (!path)
	{
		perror("search_path_command: malloc failed");
		return (NULL);
	}
	_strcpy(path, dir);
	if (dir[dir_len - 1] != '/')
	{
		_strcat(path, "/");
		_strcat(path, command);
	}
	if (access(path, X_OK) == 0)
	{
		return (path);
	}
	free(path);
	return (NULL);
}

/**
 * search_path - searches for a command within the
 * directories in the PATH variable
 * @command: the command to search for
 * Return: the path to the command, or NULL if not found
 */
char *search_path(char *command)
{
	char **dirs = NULL, *path = NULL, *result = NULL;
	int dir_idx = 0;

	if (!command)
	{	perror("search_path: invalid input");
		return (NULL); }
	result = check_path_command(command);
	if (result)
	{ return (result); }
	path = _getenv("PATH");
	if (!path)
	{	perror("search_path: PATH var not set");
		return (NULL); }
	dirs = split_path(path);
	if (!dirs)
	{	perror("search_path: PATH split fail ");
		return (NULL); }
	while (dirs[dir_idx])
	{	result = search_path_command(dirs[dir_idx], command);
		if (result)
		{ break; }
		dir_idx++;
	}
	for (dir_idx = 0; dirs[dir_idx]; dir_idx++)
	{ free(dirs[dir_idx]); }
	free(dirs);
	if (!result)
	{
		perror("search_path: cmnd not found");
		return (NULL); }
	return (result);
}
