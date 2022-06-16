#include "monty.h"

/**
 * parse_line - parses a line of code
 * @token: the token to parse
 * @stack: the stack to use
 * @line_number: the line number
 *
 * Return: void
 */
void parse_line(char *token, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t op_list[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{"stack", op_stack},
		{"queue", op_queue},
		{NULL, NULL}
	};

	while (op_list[i].opcode != NULL)
	{
		if (strcmp(op_list[i].opcode, token) == 0)
		{
			op_list[i].f(stack, line_number);
			return;
		}
		i++;
	}

	line_number++;
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
	free_stack(stack, line_number);

	exit(EXIT_FAILURE);

}
