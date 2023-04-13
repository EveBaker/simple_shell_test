#include "shell.h"
/**
 * token_line - splits the line array of tokens
 * @line: line to be tokenized
 * Return: 0 success
 */
char **token_line(char *line)
{
	unsigned int line_len = 0;
	unsigned int size = BUFFER / sizeof(char *);
	char *token = strtok(line, DELIMITERS);
char **words = malloc(size * sizeof(char *));

	if (line == NULL || *line == '\0')
	{
		return (NULL);
	}
	if (words == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		words[line_len] = token;
		line_len++;
		if (line_len >= size)
		{
			size = (unsigned int) (size * 1.5);
			words = realloc(words, size * sizeof(char *));
			if (words == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIMITERS);
		if (token == NULL && line_len == 1)
		{
			free(words);
			return (NULL);
		}
	}
	words[line_len] = NULL;
	return (words);
}
