#include "monty.h"

void opcode_func(char *opcode, stack_t **stack, unsigned int line)
{
	unsigned int i;
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
