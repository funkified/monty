#include "monty.h"

/**
 * opcode_func - find opcode in list
 * @opcode: opcode to compare
 * @stack: head of the stack
 * @line: line of command
 * Return: NOthing
 */

void opcode_func(char *opcode, stack_t **stack, unsigned int line)
{
	unsigned int i;
	instruction_t opcodes[] = {
		{"pall", pall},
		{"push", push},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			(opcodes[i].f)(stack, line);
			return;
		}
		if (opcodes[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			exit(EXIT_FAILURE);
			free(opcode);
			free_stack(stack);
		}
	}
}
/**
 * free_stack - frees memory of the stack
 * @stack: ehad 0f the stack
 * Return: Nothing
 */

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

/**
 * find_arg - finds if an arguments or parameter in opcode
 * @arg: argument to evaluate
 * Return: true if argument is found, false otherwise
 */

bool find_arg(char *arg)
{
	int i;

	for (i = 0; arg[i] != '\0'; i++)
	{
		if (arg[0] == '-')
		{
			if (isdigit(arg[i + 1]) != 0)
				continue;
			if (isdigit(arg[i + 1]) == 0)
				return (false);
		}
	}
	return (true);
}
