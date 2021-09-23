#include "monty.h"

/**
 * add - adds the 2 top elemets of a stack
 * @stack: top element of stack
 * @line: valie
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
