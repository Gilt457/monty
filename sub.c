#include "monty.h"
/**
 * f_sub - subtracts the top two elements of the stack
 * @head: pointer to the head of the stack
 * @counter: line number
 * Return: nothing
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *tmp;
	int diff, len;

	tmp = *head;
	len = 0;
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	diff = tmp->next->n - tmp->n;
	tmp->next->n = diff;
	*head = tmp->next;
	free(tmp);
}
