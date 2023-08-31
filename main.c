#include "monty.h"
int stk_qk = 0;
/**
 * main - driver function for monty program
 * @argc: int num of arguments
 * @argv: opcode file
 * Return: 0
 */
int main(int argc, char **argv)
{
	stack_t *top;

	top = NULL;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		error_exit(&top);
	}
	read_file(argv[1], &top);
	free_dlistint(top);
	return (0);
}
