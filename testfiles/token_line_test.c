#include "shell.h"
/**
  * main - test token_line function
  * Return - always 0
  */
int main()
{
        char str[] = "Hello world! This is a test.";
        char **words = token_line(str);
        /*Print the array of words*/
        for (int i = 0; words[i] != NULL; i++)
        {
                printf("%s\n", words[i]);
        }
        /*Free memory*/
        free(words);
        return (0);
}
