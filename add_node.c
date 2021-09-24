#include "monty.h"

/**
 * add_dnodeint - add a new node at the begginnig of a list
 * @head: start of the list
 * @n: new node
 * Return: the address of new element or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new = NULL, *temp = NULL;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;

	temp = *head;
	*head = new;
	new->next = temp;
	if (temp != NULL)
	{
		temp->prev = *head;
	}
	return (new);
}
