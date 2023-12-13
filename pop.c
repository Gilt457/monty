#include "monty.h"
/**
 * f_pop - removes the top element of the stack
 * @head: pointer to the head of the stack
 * @counter: line number of the instruction
 * Return: nothing
 */
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	/* check if the stack is empty */
	if (*head == NULL)
	{
		/* print error message and exit */
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/* store the top element in a temporary variable */
	temp = *head;
	/* move the head pointer to the next element */
	*head = temp->next;
	/* free the top element */
	free(temp);
}
