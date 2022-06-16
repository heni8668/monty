#include "monty.h"

/**
 * evaluate_operation - Evaluates operation given commandline input, stack/queue mode, and line number of file
 * @stack: Stack/queue to be evaluated
 * @line_number: Line number of file
 * @mode: Mode of stack/queue
 * @opcode: Operation to be evaluated
 *
 * Return: Nothing
 */
void evaluate_operation(stack_t **stack, unsigned int line_number, int mode, char *opcode)
{
	int (*f)(stack_t **, unsigned int, int);

	f = NULL;
	if (strcmp(opcode, "push") == 0)
		f = op_push;
	else if (strcmp(opcode, "pall") == 0)
		f = op_pall;
	else if (strcmp(opcode, "pint") == 0)
		f = op_pint;
	else if (strcmp(opcode, "pop") == 0)
		f = op_pop;
	else if (strcmp(opcode, "swap") == 0)
		f = op_swap;
	else if (strcmp(opcode, "add") == 0)
		f = op_add;
	else if (strcmp(opcode, "nop") == 0)
		f = op_nop;
	else if (strcmp(opcode, "sub") == 0)
		f = op_sub;
	else if (strcmp(opcode, "div") == 0)
		f = op_div;
	else if (strcmp(opcode, "mul") == 0)
		f = op_mul;
	else if (strcmp(opcode, "mod") == 0)
		f = op_mod;
	else if (strcmp(opcode, "pchar") == 0)
		f = op_pchar;
	else if (strcmp(opcode, "pstr") == 0)
		f = op_pstr;
	else if (strcmp(opcode, "rotl") == 0)
		f = op_rotl;
	else if (strcmp(opcode, "rotr") == 0)
		f = op_rotr;
	else if (strcmp(opcode, "stack") == 0)
		f = op_stack;
	else if (strcmp(opcode, "queue") == 0)
		f = op_queue;

	if (f == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
	f(stack, line_number, mode);

	return;
}
