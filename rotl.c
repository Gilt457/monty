#include "monty.h"
/**
 * f_rotl - moves the top element of the stack to the bottom
 * @head: pointer to the head of the stack
 * @counter: line number of the instruction
 * Return: nothing
 */
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	/* check if the stack is empty or has only one element */
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	/* detach the top element and store it in aux */
	aux = (*head)->next;
	aux->prev = NULL;

	/* find the last element of the stack and store it in tmp */
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	/* attach the top element to the end of the stack */
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;

	/* update the head pointer to point to the new top element */
	*head = aux;
}
