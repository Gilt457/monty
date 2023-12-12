#include "monty.h"

/**
 * print_stack_string - Prints the string starting at the top of the stack,
 * followed by a new line
 * @stack_head: Pointer to the head of the stack
 * @line_number: Line number in the file
 * Return: No return value
 */
void print_stack_string(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current_node;
	(void)line_number;

	current_node = *stack_head;

	while (current_node)
	{
		if (current_node->n > 127 || current_node->n <= 0)
		{
			break;
		}
		printf("%c", current_node->n);
		current_node = current_node->next;
	}
	printf("\n");
}
