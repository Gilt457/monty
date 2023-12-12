#include "monty.h"

/**
 * enableQueueMode - Enables queue mode
 * @stack: Pointer to the stack
 * @lineNumber: Line number in the file
 * Return: No return value
 */
void enableQueueMode(stack_t **stack, unsigned int lineNumber)
{
	(void)stack;
	(void)lineNumber;
	bus.queueEnabled = 1;
}

/**
 * addToQueue - Adds a node to the tail of the stack
 * @stack: Pointer to the stack
 * @value: New value to add
 * Return: No return value
 */
void addToQueue(stack_t **stack, int value)
{
	stack_t *newNode, *temp;

	temp = *stack;
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		printf("Error\n");
		return;
	}
	newNode->n = value;
	newNode->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*stack = newNode;
		newNode->prev = NULL;
	}
	else
	{
		temp->next = newNode;
		newNode->prev = temp;
	}
}
