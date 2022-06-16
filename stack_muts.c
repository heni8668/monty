#include "monty.h"

/**
 * op_push - pushes an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't push an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(globals.argv);
	new_node->next = *stack;
	*stack = new_node;
}

/**
 *op_pop - pops an element from the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * op_swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

/**
 * op_rotl - rotates the stack to the left
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't rotate, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->next = temp->next->next;
	temp->next->next = *stack;
	*stack = temp->next;
	temp->next = NULL;
}

/**
 * op_rotr - rotates the stack to the right
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't rotate, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}
