#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 *
 * Return: void
 */
void free_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	free(*stack);
	*stack = NULL;
	if (line_number)
		fprintf(stderr, "L%d: can't free stack\n", line_number);
}

/**
 * free_dlist - frees the doubly linked list
 * @head: pointer to the head of the doubly linked list
 *
 * Return: void
 */
void free_dlist(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
