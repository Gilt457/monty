#include "monty.h"

/**
 * f_add - computes the sum of the top two nodes of the stack
 * @head: pointer to the head of the stack
 * @counter: the current line number
 * Return: nothing
 */
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int sum = 0, size = 0;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*head = temp->next;
	free(temp);
}
