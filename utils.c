#include "main.h"
#include "shell.h"

/**
 * _calloc - function that allocates memory
 *           for an array, using malloc
 * @nmemb: number of members
 * @size: size of block in bytes
 * Return: pointer or NULL
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int index = 0;
	char *ptr = NULL;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);

	for (; index < (nmemb * size); index++)
		ptr[index] = 0;

	return (ptr);
}
/**
 * empty_line - checks if an empty line exists
 * @buff: line
 * Return: 0 or 1 (int)
 */

int empty_line(char *buff)
{
	int char_indx;

	for (char_indx = 0; buff[char_indx] != '\0'; char_indx++)
	{
		if (buff[char_indx] != ' ')
			return (0);
	}
	return (1);
}
/**
  *_strchr - locates the first occurrence of
  *            a character in a string
  * @str: the string to search
  * @c: the character to find
  * Return: pointer to the first occurrence of the char
  */
char *_strchr(char *str, char c)
{
	if (!str)
	{
		perror("my_strchr: invalid string");
		exit(EXIT_FAILURE);
	}
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}
/**
 * _strncmp - compare n bytes of two strings
 * @str1: the first string
 * @str2: the second string
 * @str_len: the maximum number of bytes to compare
 * Return: 0 if the strings are equal,
 * a negative value if s1 is less than s2,
 * or a positive value if s1 is greater than s2.
 */
int _strncmp(const char *str1, const char *str2, size_t str_len)
{
	unsigned char s1char, s2char;

	while (str_len--)
	{
		s1char = (unsigned char)*str1++;
		s2char = (unsigned char)*str2++;

		if (s1char != s2char)
			return (s1char - s2char);
		if (!s1char)
			break;
	}
	return (0);
}
