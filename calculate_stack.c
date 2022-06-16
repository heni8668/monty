#include "monty.h"

/**
 * op_add - adds the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the instruction
 * Return: void
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	temp->n += (*stack)->n;
	free(*stack);
	*stack = temp;
}

/**
 * op_sub - subtracts the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the instruction
 * Return: void
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	temp->n -= (*stack)->n;
	free(*stack);
	*stack = temp;
}

/**
 * op_div - divides the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the instruction
 * Return: void
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(*stack, line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	temp->n /= (*stack)->n;
	free(*stack);
	*stack = temp;
}

/**
 * op_mul - multiplies the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the instruction
 * Return: void
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(*stack, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	temp->n *= (*stack)->n;
	free(*stack);
	*stack = temp;
}

/**
 * op_mod - modulus the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the instruction
 * Return: void
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(*stack, line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	temp->n %= (*stack)->n;
	free(*stack);
	*stack = temp;
}
