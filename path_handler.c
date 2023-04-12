#include "main.h"
#include "shell.h"
/**
 * dir_count - counts the number of directories
 *            in the PATH variable
 * @path_str: the PATH variable string
 * Return: the number of directories
 */
int dir_count(char *path_str)
{
	int count_dirs = 0;
	char *current_char = path_str;

	if (!path_str)
	{
		perror("dir_count");
		exit(EXIT_FAILURE);
	}

	while (*current_char)
	{
		if (*current_char == ':')
			count_dirs++;
		current_char++;
	}
	count_dirs++;

	return (count_dirs);
}
/**
 * split_path - splits the PATH variable into
 *              individual directories
 * @path: the PATH variable string
 * Return: array of pointers to individual directories
 */
char **split_path(char *path)
{
	char **dirs = NULL, *dir = NULL;
	int dir_idx = 0, count_dirs = 0;

	if (!path)
	{
		perror("split_path:path is NULL");
		exit(EXIT_FAILURE);
	}
	count_dirs = dir_count(path);
	dirs = malloc(sizeof(char *) * count_dirs);
	if (!dirs)
	{
		perror("split_path: malloc failed");
		exit(EXIT_FAILURE);
	}
	dir = strtok(path, ":");
	while (dir)
	{
		dirs[dir_idx] = malloc(strlen(dir) + 1);
		if (!dirs[dir_idx])
		{
			perror("split_path: malloc failed");
			exit(EXIT_FAILURE); }
		_strcpy(dirs[dir_idx], dir);
		dir_idx++;
		dir = strtok(NULL, ":");
	}
	dirs[dir_idx] = NULL;
	for (dir_idx = 0; dirs[dir_idx]; dir_idx++)
	{
		free(dirs[dir_idx]);
		free(dirs);
	}
	return (dirs);
}

/**
 * search_dir - searches for a command within
 *              a single directory
 * @dir: the directory to search
 * @command: the command to search for
 * Return: the path to the command, or NULL if not found
 */
char *search_dir(char *dir, char *command)
{
	char *path = NULL;
	int dir_len = _strlen(dir);
	int cmd_len = _strlen(command);

	if (!dir || !command)
	{
		perror(" search_dir: invalid input");
		exit(EXIT_FAILURE);
	}
	path = malloc(dir_len + cmd_len + 2);
	if (!path)
	{
		perror("search_dir: malloc failed");
		exit(EXIT_FAILURE);
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
