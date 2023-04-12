#include "shell.h"
/**
  * splint_line - splits the line into array of
  *              tokens using strtok
  * Return: 0 success
  */
#define MAX_WORDS 100

char** split_line(char *str)
{
	char **words, *word;
	int i = 0;
/*allocate memory for the array of words*/
	if (str == NULL || *str == '\0')
	{
		perror("command not found");
		exit(EXIT_FAILURE);
	}

	words = malloc(MAX_WORDS * sizeof(char *));
	if (words == NULL)
	{
		perror("Error: unable to allocate memory for words array");
		exit(EXIT_FAILURE);
	}
/* Split string into words with strtok*/
	word = strtok(str, " ");
	while (word != NULL)
	{
		words[i] = word;
		i++;
		word = strtok(NULL, " ");
	}
/*set last element to NULL: end of array*/
	words[i] = NULL;

	return (words);
}
