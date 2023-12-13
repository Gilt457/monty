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
	while (temp) /* loop through the stack and count the nodes */
	{
		temp = temp->next;
		size++;
	}
	if (size < 2) /* check if the stack has at least two nodes */
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sum = temp->n + temp->next->n; /* calculate the sum of the top two nodes */
	temp->next->n = sum; /* assign the sum to the second node */
	*head = temp->next; /* move the head pointer to the second node */
	free(temp); /* free the first node */
}
