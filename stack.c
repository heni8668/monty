#include "monty.h"
stack_t *head = NULL;

/**
 * new_node - new node.
 *
 * @n: num.
 *
 * Return: pointer to new node or NULL.
 */

stack_t *new_node(int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		error(4);

	new->next = NULL;
	new->prev = NULL;
	new->n = n;

	return (new);
}

/**
 * free_stack - free stack.
 */

void free_stack(void)
{
	stack_t *tmp;

	if (!head)
		return;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * _push - Push node to stack.
 *
 * @new_node: pointer new node.
 *
 * @line_number: line number.
 */

void _push(stack_t **new_node, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (!new_node || !(*new_node))
		exit(EXIT_FAILURE);
	if (!head)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;

}

/**
 * _pop - removes the top element of the stack.
 *
 * @stack: pointer the stack.
 * @line_number: line number.
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack))
		monty_error(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}
