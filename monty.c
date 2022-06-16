#include "monty.h"

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	FILE *fd;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *head = NULL;
	int mode = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fd)) != -1)
	{
		evaluate_operation(&line, &line_number, mode, &head);
		line_number++;
	}

	free(line);
	fclose(fd);
	free_dlist(head);
	return (0);
}
