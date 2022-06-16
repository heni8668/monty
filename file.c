#define  _GNU_SOURCE
#include "monty.h"

/**
 * open_file - open file
 *
 * @file_name: file name
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		error(2, file_name);

	read_file(fd);

	fclose(fd);
}

/**
 * read_file - read file
 *
 * @fd: file descriptor
 */

void read_file(FILE *fd)
{
	int line_number;
	char *line = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&line, &len, fd) != -1; line_number++)
	{
		token_line(line, line_number);
	}

	free(line);
}

/**
 * token_line - line to tokens
 *
 * @line: line from file
 * @line_number: line number
 */

void token_line(char *line, int line_number)
{
	char *opcode, *value;

	if (line == NULL)
		error(4);

	opcode = strtok(line, DELIM);
	value = strtok(NULL, DELIM);

	get_func(opcode, value, line_number);
}
