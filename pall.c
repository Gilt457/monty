#include "monty.h"
/**
 * f_pall - Prints all the elements of a stack
 * @head: Pointer to the top of the stack
 * @counter: Unused parameter
 * Return: Nothing
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *current;

	(void)counter;
	current = *head;
	if (current == NULL)
		return;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
