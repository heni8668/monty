#include "monty.h"

/**
 * handle_error - handles errors
 * @error_code: error code
 * @line_number: line number
 *
 * Return: void
 */
void handle_error(int error_code, unsigned int line_number)
{
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					global_vars.file_name);
			break;
		case 3:
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			break;
		case 4:
			fprintf(stderr, "L%u: usage: pall\n", line_number);
			break;
		case 5:
			fprintf(stderr, "L%u: usage: pop\n", line_number);
			break;
		case 6:
	}
	exit(EXIT_FAILURE);
}