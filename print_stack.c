#include "monty.h"

/**
 * op_pall - prints all the values on the stack
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * op_pint - prints the value at the top of the stack
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	printf("%d\n", temp->n);
}

/**
 * op_phcar - prints the value at the top of the stack
 * @stack: stack
 * @line_number: line number
 * @h: head
 * @c: counter
 * @n: number
 *
 * Return: void
 */
void op_phcar(stack_t **stack, unsigned int line_number, stack_t *h, int c, int n)
{
	(void)line_number;
	(void)h;
	(void)c;
	(void)n;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * op_pstr - prints the string at the top of the stack
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pstr, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	printf("%s\n", temp->str);
}

/**
 * op_nop - does nothing
 * @stack: stack
 * @line_number: line number
 * @h: head
 * @c: counter
 * 
 * Return: void 
 */
void op_nop(stack_t **stack, unsigned int line_number, stack_t *h, int c)
{
	(void)stack;
	(void)line_number;
	(void)h;
	(void)c;
}
