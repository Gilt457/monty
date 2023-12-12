#include "monty.h"

/**
 * print_top_element - Prints the top element of the stack
 * @stack_head: Pointer to the stack's head
 * @line_counter: Line number
 * Return: No return value
 */
void print_top_element(stack_t **stack_head, unsigned int line_counter)
{
	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't print, stack empty\n", line_counter);
		fclose(bus_context.file_pointer);
		free(bus_context.content_pointer);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_head)->value);
}
