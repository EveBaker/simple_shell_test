#include "shell.h"

/**
* _print_env - prints the environment built-in
* Return: nothing
*/

void _print_env(void)
  
{
  int i = 0;
  
  while (environ[i])
  {
    printf("%s\n",environ[i]);
    i++;
  }
}
