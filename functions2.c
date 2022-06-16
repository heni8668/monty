#include "monty.h"

/**
 * _sub - subtracts the top element of the stack from the second top element
 *
 * @stack: Pointer stack.
 * @line_number: line number.
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	int sub;

	if (!stack || !(*stack) || !((*stack)->next))
		monty_error(8, line_number, "sub");

	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;

	free((*stack)->prev);

	(*stack)->prev = NULL;
}

/**
 * _div -  divides the second top element of the stack by the top element.
 *
 * @stack: Pointer to stack.
 * @line_number: line number.
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int div;

	if (!stack || !(*stack) || !((*stack)->next))
		monty_error(8, line_number, "div");

	if ((*stack)->n == 0)
		monty_error(9, line_number);

	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;

	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _mul - multiplies the second top element of the stack with the top element.
 *
 * @stack: Pointer to stack.
 * @line_number: line number.
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	int mul;

	if (!stack || !(*stack) || !((*stack)->next))
		monty_error(8, line_number, "mul");

	(*stack) = (*stack)->next;
	mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = mul;

	free((*stack)->prev);
	(*stack)->prev = NULL;
}
