#include "monty.h"

void opcode_func(char *opcode, stack_t **stack, unsigned int line)
{
	int i;
	instruction_t opcodes[] = {
		{"pall", pall},
		{"push", push},
		{"pint", pint},
		{NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			(opcodes[i].f)(stack, line);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
	exit(EXIT_FAILURE);
}

void file_exec(FILE *file)
{

	unsigned int line_number = 0;
	char *line = NULL;
	char *opcode = NULL;
	char *arg = NULL;
	size_t size = 0;
	stack_t *stack = NULL;

	while (getline(&line, &size, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n");
		/*printf("opcode antes de:%s\n", opcode);*/
		if (opcode == NULL || strchr(opcode, '#') != NULL)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			/*printf("opcode push:%s\n", opcode);*/
			arg = strtok(NULL, " \n");
			if (arg != NULL)/* && valid_arg(arg)*/
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
		{
			/*printf("opcode difpush:%s\n", opcode);*/
			opcode_func(opcode, &stack, line_number);
		}
	}
	free(opcode);
	free_stack(&stack);
}
void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
		return;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		(*stack) = temp;
	}
}
