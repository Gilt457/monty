#include "monty.h"

/**
 * add_node_to_stack - Adds a new node to the head of the stack
 * @head: Pointer to the head of the stack
 * @value: Value to be added to the new node
 *
 * Return: No return value
 */
void add_node_to_stack(stack_t **head, int value)
{
	stack_t *new_elem, *temp;

	temp = *head;
	new_elem = malloc(sizeof(stack_t));

	if (new_elem == NULL)
	{
		printf("Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	if (temp != NULL)
		temp->prev = new_elem;

	new_elem->n = value;
	new_elem->next = *head;
	new_elem->prev = NULL;
	*head = new_elem;
}
