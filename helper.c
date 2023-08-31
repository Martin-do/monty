#include "monty.h"
/**
 * error_exit - frees the stack and exits due to erro
 * @stack: pointer to the head of the stack
 *
 */
void error_exit(stack_t **stack)
{
	if (*stack)
		free_dlistint(*stack);
	exit(EXIT_FAILURE);
}

/**
 * isnumber - checks if a string is a number
 * @str: string being passed
 *
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isnumber(char *str)
{
	unsigned int i;

	/*printf("i am in isnumber and data here is: %ss\n", str);*/
	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] && str[i] != '$' && str[i + 1] != '\n')
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * _rotl - rotates the list left
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _rotl(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;
	int temp1, temp2;

	if (*stack == NULL)
		return;
	runner = *stack;
	while (runner->next)
		runner = runner->next;
	while (runner)
	{
		if (!runner->next)
		{
			temp1 = runner->n;
			runner->n = (*stack)->n;
		}
		else
		{
			temp2 = runner->n;
			runner->n = temp1;
			temp1 = temp2;
		}
		runner = runner->prev;
	}
}
/**
 * _rotr - rotates the list right
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _rotr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner1, *runner2;
	int temp1, temp2;

	if (*stack == NULL)
		return;

	runner1 = *stack;
	runner2 = *stack;
	while (runner1->next)
		runner1 = runner1->next;
	while (runner2)
	{
		if (runner2->prev == NULL)
		{
			temp1 = runner2->n;
			runner2->n = runner1->n;
		}
		else
		{
			temp2 = runner2->n;
			runner2->n = temp1;
			temp1 = temp2;
		}
		runner2 = runner2->next;

	}
}


/**
 * opcodeOrNot - function that checks if command is an opcode
 * @string: command extracted from line
 * Return: returns 0 if string is an opcode or 1 if not
*/
int opcodeOrNot(char *string)
{
	int listSize;

	const char *stringList[] = {
		"pall", "push", "pint", "pop", "swap",
		"pchar", "add", "sub", "mul", "div", "mod",
		"nop", "rotl", "rotr", "pstr", "stack", "queue"
		};
	listSize = sizeof(stringList) / sizeof(stringList[0]);


	if (isStringInList(string, stringList, listSize))
		return (0);

	return (1);
}
