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
/**
 * nop - function that doesnt do anything
 * @stack: top of the stack
 * @line: line nu,ber of stack
 * Return: Nothing
 */
void nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}

/**
 * sub - substract the top element of the stacj from the second top element
 * @stack: top element of stack
 * @line: line number
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
