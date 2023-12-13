#include "monty.h"
/**
 * f_mul - multiplies the top two elements of the stack
 * @head: pointer to the stack head
 * @counter: line number
 * Return: nothing
 */
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int length = 0, product;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	product = temp->next->n * temp->n;
	temp->next->n = product;
	*head = temp->next;
	free(temp);
}
