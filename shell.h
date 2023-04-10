#ifndef SHELL_H
#define SHELL_H
/*GLOBAL LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>
#include <errno.h>
#include <signal.h>




/*CONSTANT MACROS*/
#define BUFFER 1024
#define MAX_WORDS 100
#define MAX_COMMAND_LEN 100


/*GLOBAL VARIABLES*/

extern char **environ;

/*GLOBAL STRUCTURES*/

/**
  * struct path_node - struct for LinkList
  * nodes created for directory PATH
  * Return: Always 0
  */
typedef struct path_node
{
	char *directory;
	struct path_node *next;
} path_node;

int main(void);
int shell(void);
int check_builtin_func(char *argv[], char **env);
int shell_cd(char *argv[], __attribute__((unused)) char **env);
int shell_env(__attribute__((unused)) char *argv[], char **environ);
int shell_exit(__attribute__((unused)) char *argv[];
int _execve(__attribute__((unused)) char *path, char *argv[], char **env);
char *search_path(char *command);
char *_getenv(char *name);
char *_get_line();
int _strlen(char *s);
int split_line(char *line, char *argv[]);	       
/*TEST*/
void simple_shell(void);

/* found in builtins.c */
int hshell_exit(void);
int hshell_env(void);
size_t count_tokens(char **tokens);
/*functions from practice?? needed?*/


#endif
