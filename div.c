#include "monty.h"
/**
 * f_div - performs division operation on the top two elements of the stack
 * @head: pointer to the top of the stack
 * @counter: line number of the current instruction
 * Return: void
 */
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *node;
	int len = 0, quotient;

	node = *head;
	/* loop through the stack and count the nodes */
	while (node)
	{
		node = node->next;
		len++;
	}
	/* verify that the stack has enough elements for division */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	node = *head;
	/* verify that the top element is not zero to avoid division by zero */
	if (node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	quotient = node->next->n / node->n;
	node->next->n = quotient;
	*head = node->next;
	free(node);
}
