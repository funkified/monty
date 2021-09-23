#include "monty.h"

/**
 * pint - prints the value at the top of stack
 * @stack: pointer to head;
 * @line: line pointer
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line)
{
	stack_t *temp;

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
/**
 * swap - swap the two top elements in stack
 * @stack: top of the stack
 * @line: data of the element to be swap
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line)
{
	int data;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line);
		exit(EXIT_FAILURE);
	}
	data = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = data;
}
