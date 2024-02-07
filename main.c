#include "monty.h"

/**
 * main - MAin
 * @argc: num of arguments
 * @argv: vector of arguments
 * Return: 0
*/

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	size_t bufsize = 0;
	char *file = *(argv + 1), *input_line = NULL;
	FILE *fp;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(file, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while (getline(&input_line, &bufsize, fp) != -1)
	{
		read_line(input_line, line_number, &stack);
		line_number++;
	}
	free(input_line);
	free_stack(stack);
	fclose(fp);
	return (0);
}
