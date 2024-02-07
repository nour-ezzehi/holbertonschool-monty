#include "monty.h"

/**
 * read_line - read and parse the readen line
 * @input_line: the read line
 * @stack: the stack
 * @line_num: line's num
*/

char *arg;

void read_line(char *input_line, unsigned int line_num, stack_t **stack)
{
	char *opcode = NULL;

	opcode = strtok(input_line, TOKDELIM);
	if (opcode)
	{
		arg = strtok(NULL, TOKDELIM);
		if (!strcmp(opcode, "push") && (!arg || !check_num(arg)))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			free_stack(*stack);
			free(input_line);
			exit(EXIT_FAILURE);
		}
		else
			execute(opcode, line_num, stack);
	}
}
