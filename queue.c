#include "monty.h"

/**
 * f_queue - sets the format to queue
 * @head: pointer to the head of the stack
 * @counter: line number of the instruction
 * Return: nothing
 */
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - adds a node to the end of the stack
 * @n: value of the new node
 * @head: pointer to the head of the stack
 * Return: nothing
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		return;
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux == NULL)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new_node;
		new_node->prev = aux;
	}
}
