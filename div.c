#include "monty.h"

/**
 * div - divide the elemetn of the top of the stack
 * @stack: top of the stack
 * @line: number of line
 * Return: Nothing
 */

void _div(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
