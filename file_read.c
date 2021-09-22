#include "monty.h"

char *args;

/**
 * file_exec - open an excecute a file
 * @file: file to be excecute
 * Return: nothing
 */

void file_exec(FILE *file)
{

	unsigned int line_number = 0;
	char *line = NULL;
	char *opcode = NULL;
	size_t size = 0;
	stack_t *stack = NULL;

	while (getline(&line, &size, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n\t\r");
		if (opcode == NULL || strchr(opcode, '#') != NULL)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			args = strtok(NULL, " \n\t\r");
			if (args != NULL || find_arg(args))
			{
				push(&stack, line_number);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free(opcode);
				free_stack(&stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
		}
		else
			opcode_func(opcode, &stack, line_number);
	}
	free(opcode);
	free_stack(&stack);
}

