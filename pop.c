#include "monty.h"

/**
 * pop - deletes elements in a stack
 * @stack: top of the stack
 * @line: element in line
 * Return: Nothing
 */

void pop(stack_t **stack, unsigned int line)
{

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	/* if stack is more than 1 node, else free entire thing */
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
