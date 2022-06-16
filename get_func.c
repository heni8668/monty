#include "monty.h"

/**
 * get_func - find function
 *
 * @opcode: opcode
 * @value: argument of opcode
 * @line_number: line number
 */

void get_func(char *opcode, char *value, int line_number)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"nop", _nop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, line_number);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, line_number, opcode);
}

/**
 * call_fun - Call function.
 *
 * @func: Pointer to function
 * @opcode: opcode
 * @value: value
 * @line_number: line numeber for the instruction
 */

void call_fun(op_func func, char *opcode, char *value, int line_number)
{
	stack_t *node;
	int flag = 1;
	int i;

	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			monty_error(5, line_number);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				monty_error(5, line_number);
		}
		node = new_node(atoi(value) * flag);

		func(&node, line_number);
	}
	else
		func(&head, line_number);
}
