#include "monty.h"

/**
 * print_stack - prints the elements of the stack
 * @stack_head: pointer to the head of the stack
 * @count: unused variable
 *
 * Description: This function prints all the elements of the stack.
 * It takes the stack's head as input and prints each element's value.
 */
void print_stack(stack_t **stack_head, unsigned int count)
{
	stack_t *current_node;
	(void)count;

	current_node = *stack_head;

	if (current_node == NULL)
		return;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
