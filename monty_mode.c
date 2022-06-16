#include "monty.h"

/**
 * op_stack - pushes an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 *
 * Return: nothing 
 */
void op_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't peek, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "L%d: can't malloc\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = (*stack)->n;
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * op_queue - pushes an element to the queue
 * @stack: pointer to the top of the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void op_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't peek, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "L%d: can't malloc\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = (*stack)->n;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}
	new_node->next = (*stack)->next;
	(*stack)->next = new_node;
}
