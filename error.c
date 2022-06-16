#include "monty.h"

/**
 * error - Print error messages.
 * @error_code: error code
 */

void error(int error_code, ...)
{
	va_list arg;
	char *opcode;
	int line_number;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(arg, char *));
			break;
		case 3:
			line_number = va_arg(arg, int);
			opcode = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * monty_error - monty errors.
 * @error_code: error code
 */

void monty_error(int error_code, ...)
{
	va_list arg;
	char *opcode;
	int line_number;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(arg, int));
			break;
		case 8:
			line_number = va_arg(arg, unsigned int);
			opcode = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, opcode);
			break;
		default:
			break;
	}
	free_stack();
	exit(EXIT_FAILURE);
}
