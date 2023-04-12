#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: pointer to string 1
 * @s2: pointer to string 2
 * Return: result
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);

		s1++;
		s2++;
	}
	return (0);
}

/**
 * _strcpy - function that copies the string to
 *           the buffer
 * @dest_buf: buffer to copy the string to
 * @src_str: the string to copy
 * Return: a ptr to the destination string dest
 */
char *_strcpy(char *dest_buf, char *src_str)
{
	char *buf_head = dest_buf;

	while (*src_str != '\0')
	{
		*dest_buf = *src_str;
		dest_buf++;
		src_str++;
	}
	*dest_buf = '\0';
	return (buf_head);
}

/**
 * string_tokenize - uses strtok to split strings
 * @str: string to tokenize
 * @sep: separator string
 * Return: an array of strings split by separator
 */

char **string_tokenize(char *str, char *sep)
{
	char *sub_strs, **split_str;
	int substr_idx = 0;

	sub_strs = strtok(str, sep);
	split_str = (char **)_calloc(100, sizeof(char *));

	if (!split_str)
	{
		free(split_str);
		return (NULL);
	}

	while (sub_strs)
	{
		split_str[substr_idx] = sub_strs;
		sub_strs = strtok(NULL, sep);
		substr_idx++;
	}
	return (split_str);
}

/**
 * _strcat - function that concatenates two strings
 * @dest: string where concat string is stored
 * @src: string to be concaternated to dest string
 * Return: a pointer to destination string
 */

char *_strcat(char *dest, char *src)
{
	int dst_idx, src_idx;

	for (dst_idx = 0; dest[dst_idx] != '\0'; dst_idx += 1)
	{ /* finds end of dest string & moves on */}

	for (src_idx = 0; src[src_idx] != '\0'; src_idx += 1)
	{
		dest[dst_idx] = src[src_idx];
		dst_idx++;
	}
	dest[dst_idx] = '\0';
	return (dest);
}

/**
 * _strlen - calculates string length
 * @str: string given as input
 * Return: result of string length
 */

int _strlen(char *str)
{
	int str_idx = 0;

	while (str[str_idx] != '\0')
		str_idx++;

	return (str_idx);
}
