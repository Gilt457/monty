#include "monty.h"
/**
 * f_div - divides the second element of the stack by the first
 * @head: pointer to the head of the stack
 * @counter: line number of the instruction
 * Return: nothing
 */
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int length = 0, result;

	temp = *head;
	/* count the number of nodes in the stack */
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	/* check if the stack has at least two elements */
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	/* check if the top element is zero */
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = temp->next->n / temp->n;
	temp->next->n = result;
	*head = temp->next;
	free(temp);
}
