#include "monty.h"

/**
 * run_function - runs specified the function
 * @stack: pointer to the top of the stack
 * @line_number: line number of the file
 * @opcode: the opcode of the function
 *
 * Return: void
 */
void run_function(stack_t **stack, char *opcode, unsigned int line_number)
{
	instruction_t functions[] = {
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
		{NULL, NULL}};
	int i = 0;

	while (functions[i].opcode != NULL)
	{
		if (strcmp(functions[i].opcode, opcode) == 0)
		{
			functions[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_stack(stack, line_number);
	exit(EXIT_FAILURE);
}
