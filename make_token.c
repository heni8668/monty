#include "monty.h"

/**
 * make_token - function that creates a token
 * @input: input
 * @stack: stack argument
 * @line_number: line number
 *
 * Return: token
 */
void make_token(char *input, stack_t **stack, unsigned int line_number)
{
	char *token;
	char *token_copy;

	token = strtok(input, " \t\n\r");

	if (token == NULL || token[0] == '#' || token[0] == '\0' ||
		token[0] == '\n')
		return;

	if (strcmp(token, "push") == 0)
	{
		token_copy = strdup(token);
		token = strtok(NULL, " \t\n\r");

		if (!bool_num(token))
		{
			line_number++;
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_stack(stack, line_number);
			exit(EXIT_FAILURE);
		}

		push(stack, atoi(token), line_number);
		parse_line(token_copy, stack, line_number);
	}

	else
	{
		parse_line(token, stack, line_number);
	}
}

/**
 * bool_num - function that checks if a string is a number
 * @token: string to be checked
 *
 * Return: 1 if it is a number, 0 if it is not
 */
int bool_num(char *token)
{
	int i;

	if (token[0] == '-')
		i = 1;
	else
		i = 0;

	for (; token[i] != '\0'; i++)
	{
		if (token[i] < '0' || token[i] > '9')
			return (0);
	}

	return (1);
}
