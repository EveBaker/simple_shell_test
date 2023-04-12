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
#define MAX_WORDS 20
#define MAX_COMMAND_LEN 100
#define  DELIMITERS " \t\r\n"
#define PROMPT "$ "
/*GLOBAL VARIABLES*/

extern char **environ;

/*GLOBAL STRUCTURES*/

<<<<<<< HEAD
=======
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

>>>>>>> 6a2db32cb4cd7fe4d576e3a077de8b48f70d1eb5
int main(void);
char *read_line(void);/* reads shell command line*/
char **token_line(char *line);/* tokenizes delimiters*/
void exec_line(char **args);/*execute command line*/
int exec_builtin_cmds(char **);
int print_env(void) /* prints enviroment variables*/
char *strtok(char *str, const char *delim);


/* found in shell_pers.c */
void print_prompt(void);

/*TEST*/
void simple_shell(void);

/* found in builtins.c */
int hshell_exit(void);
int hshell_env(void);
size_t count_tokens(char **tokens);
/*functions from practice?? needed?*/
char** split_line(char *str);

#endif
