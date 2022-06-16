#include "monty.h"

/**
 * main - Main file for Monty
 *
 * @ac: arguments count
 * @av: arguments
 *
 * Return: EXIT_SUCCESS on success EXIT_FAILURE on error
 */

int main(int ac, char **av)
{
	stack_t *head = NULL;
	(void)head;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	open_file(av[1]);
	free_stack();

	return (0);
}
