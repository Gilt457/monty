#include "monty.h"

/**
 * divide_top_two_elements - Divides the top two elements of the stack.
 * @stack_head: Pointer to the stack's head
 * @line_number: Line number in the file
 * Return: No return value
 */
void divide_top_two_elements(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current_node;
	int stack_length = 0, division_result;

	current_node = *stack_head;

	/* Calculate the length of the stack */
	while (current_node)
	{
		current_node = current_node->next;
		stack_length++;
	}

	/* Check if the stack has less than two elements */
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: cannot divide, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	current_node = *stack_head;

	/* Check for division by zero */
	if (current_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	division_result = current_node->next->n / current_node->n;
	current_node->next->n = division_result;
	*stack_head = current_node->next;
	free(current_node);
}
