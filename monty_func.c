#include "monty.h"

/**
 * get_op_func -  checks opcode and returns the correct function
 * @str: the opcode
 *
 * Return: returns a function, or NULL on failure
 */
instruct_func get_op_func(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", push_stack},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"pchar", _pchar},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"nop", _nop},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"pstr", _pstr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

/**
 * isStringInList - checks if string in a list
 * @target: the string to be checked
 * @stringList: the list of strings
 * @listSize: the size of the list
 * Return: returns 0 if string not found or 1 if found
*/
int isStringInList(const char *target, const char *stringList[], int listSize)
{
	int i;

	for (i = 0; i < listSize; i++)
	{
		if (strcmp(target, stringList[i]) == 0)
			return (1);
	}
	return (0);
}



/**
 * check_push_arg - function that check argument of push
 * opcode
 * @data: the argument of the push opcode
 * @line_num: the line number of the opcode
 * @top: pointer to the top of the stack
 * Return: returns 1 if a valid argument
*/
int check_push_arg(char *data, int line_num, stack_t **top)
{
	if (isnumber(data) == 0  || data == NULL)
	{
		printf("L%d: usage: push integer\n", line_num);
		error_exit(top);
	}
	return (1);
}

/**
 * execute - to execute the opcode command
 * @opcode: the opcode command
 * @data: the data to be push if it is a push opcode
 * @line_count: the line number being executed
 * @top: a pointer to the top of the stack
 * @s: the function of the required opcode
 * Return: return nothing since a void function
*/
void execute(char *opcode, char *data, int line_count, stack_t **top,
		instruct_func s)
{
	if (strcmp(opcode, "push") == 0)
	{
		if (check_push_arg(data, line_count, top) == 1)
			s(top, atoi(data));
		else
			error_exit(top);
	}
	else
		s(top, line_count);
}


/**
 * read_file - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @top: pointer to the top of the stack
 *
 */
void read_file(char *filename, stack_t **top)
{
	char *opcode, *data;
	char line[100];
	int line_count = 0, check;
	instruct_func s;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		error_exit(top);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (line != NULL)
		{
			opcode = strtok(line, " ");
			data = strtok(NULL, " ");
			if (line == NULL || line[0] == '#')
			{
				line_count++;
				continue;
			}
			if (opcodeOrNot(opcode) == 0)
			{
				line_count++;
				s = get_op_func(opcode);
				if (s == NULL)
				{
					printf("L%d: unknown instruction %s\n", line_count, opcode);
					error_exit(top);
				}
				else
					execute(opcode, data, line_count, top, s);
			}
		}
	}
	check = fclose(file);
	if (check == -1)
		exit(-1);
}
