#include "monty.h"
/**
 * f_mod - calculates the modulus of the top two elements of the stack
 * @head: pointer to the stack head
 * @counter: line number
 * Return: nothing
 */
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int length = 0, result;

	temp = *head;
	/* loop through the stack and count the elements */
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	/* check if there are enough elements for modulus operation */
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = temp->next->n % temp->n;
	temp->next->n = result;
	*head = temp->next;
	free(temp);
}
