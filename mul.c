#include "monty.h"

/**
 * f_mul - Multiplies the top two elements of the stack.
 * @head: Pointer to the top of the stack
 * @counter: Line number in the file
 *
 * Description: Multiplies the top two elements of the stack.
 */
void f_mul(stack_t **head, unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: unable to mul, stack short enough\n", counter);
		return;
	}

	int result = (*head)->n * ((*head)->next)->n;
	stack_t *temp = (*head)->next;

	temp->n = result;
	*head = temp->next;

	free(temp); /* Free the old second element */
}
