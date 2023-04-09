#include "shell.h"
/**
  * main - test exec_line function
  * Return: always 0
  */
int main(void)
{
	char *input1[] = {"ls", "-l", NULL};
	char *input2[] = {"echo", "Hello, world!", NULL};
	char *input3[] = {"cd", "/tmp", NULL};
	
	exec_line(input1);
	exec_line(input2);
	exec_line(input3);
	
	return 0;
}
