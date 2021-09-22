#include "monty.h"

/**
 * push - push element to stack
 *@n: element
 * Return: true if its not empty, False otherwise
 */
void push(stack_t **stack, unsigned int n)
{
	stack_t *new = NULL;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: Error stack not found\n", n);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*stack != NULL)
	{
		new->next = *stack;
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
		*stack = new;
	}
	if (*stack == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	}
/*	new->n = atoi(arg);
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
*/
}

void pall(stack_t **stack, unsigned int line)
{
	stack_t *temp;
	(void)line;
	
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
