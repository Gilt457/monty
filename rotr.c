#include "monty.h"

/**
 * f_rotr - rotates the stack to the bottom
 * @head: pointer to the head of the stack
 * @counter: line number (unused)
 * Return: nothing
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *last;

	last = *head;
	/* check if stack is empty or has one element */
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	/* find the last node of the stack */
	while (last->next)
	{
		last = last->next;
	}
	/* make the last node the new head and detach it from the previous node */
	last->next = *head;
	last->prev->next = NULL;
	last->prev = NULL;
	(*head)->prev = last;
	*head = last;
}
