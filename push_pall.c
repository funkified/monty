#include "monty.h"

char *args;

/**
 * push - push element to stack
 *@n: element
 *@stack: top of the stack
 *Return: true if its not empty, False otherwise
 */

void push(stack_t **stack, unsigned int n)
{
	stack_t *new = NULL;

	if (stack == NULL || args == NULL)
	{
		fprintf(stderr, "L%d: Error stack not found\n", n);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t) * 1024);
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(args);
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	(*stack) = new;
}

/**
 * pall - prints all element in a stack
 * @stack: top of the stack
 * @line: elements
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int line)
{
	stack_t *temp;
	(void)line;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		if (temp == *stack)
			return;
	}
}
