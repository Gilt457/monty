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

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}
