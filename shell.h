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
char *read_line(void);/* reads shell command line*/
char **token_line(char *line);/* tokenizes delimiters*/
void exec_line(char **args);/*execute command line*/
int exec_builtin_cmds(char **);
char *_getenv(const char *name) /* prints enviroment variables*/
char **copy_env(char **environ_copy, unsigned int environ_length) /* copys env */


/*TEST*/
void simple_shell(void);

/* found in builtins.c */
int hshell_exit(void);
int hshell_env(void);
size_t count_tokens(char **tokens);
/*functions from practice?? needed?*/


#endif
