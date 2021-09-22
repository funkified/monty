#include "monty.h"
/**
 * pint - prints the value at the top of stack
 * @stack: pointer to head;
 * @line: line pointer
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line)
{
	stack_t *temp = NULL;
	
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: cant't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp)
	{
		if (temp->prev == NULL)
			break;
		temp = temp->prev;
	}
	printf("%d\n", temp->n);

}

