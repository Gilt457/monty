#include "monty.h"

/**
 * add_top_two_elements - Add the top two items of the stack.
 * @head: Pointer to the stack's head.
 * @counter: Line number.
 *
 * Return: No return value.
 */
void add_top_two_elements(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int stack_length = 0, sum;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		stack_length++;
	}

	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't sum, stack too short\n", counter);
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
