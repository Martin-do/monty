#include "monty.h"
/**
 * _add - adds top of stack and second top of stack
 *
 * @top: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _add(stack_t **top, unsigned int line_number)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		error_exit(top);
	}
	(*top)->next->n += (*top)->n;
	_pop(top, line_number);
}

/**
 * _sub - subtracts top of stack and second top of stack
 *
 * @top: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _sub(stack_t **top, unsigned int line_number)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		error_exit(top);
	}
	(*top)->next->n -= (*top)->n;
	_pop(top, line_number);
}

/**
 * _mul - multiply top of stack and second top of stack
 * @top: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _mul(stack_t **top, unsigned int line_number)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		error_exit(top);
	}
	(*top)->next->n *= (*top)->n;
	_pop(top, line_number);
}

/**
 * _div - divide top of stack and second top of stack
 * @top: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _div(stack_t **top, unsigned int line_number)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		error_exit(top);
	}
	if ((*top)->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		error_exit(top);
	}
	(*top)->next->n /= (*top)->n;
	_pop(top, line_number);
}

/**
 * _mod - mod top of stack and second top of stack
 * * @top: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _mod(stack_t **top, unsigned int line_number)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		error_exit(top);
	}
	if ((*top)->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		error_exit(top);
	}
	(*top)->next->n %= (*top)->n;
	_pop(top, line_number);
}
