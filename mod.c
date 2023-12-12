#include "monty.h"

/**
 * mod_operation - Computes the remainder of the division of the second
 * top element of the stack by the top element of the stack
 * @stack_head: Pointer to the head of the stack
 * @line_number: Line number in the file
 * Return: No return value
 */
void mod_operation(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current;
	int stack_length = 0, result;

	current = *stack_head;

	/* Calculate the length of the stack */
	while (current)
	{
		current = current->next;
		stack_length++;
	}

	/* Check if there are enough elements in the stack */
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't perform mod, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	current = *stack_head;

	/* Check for division by zero */
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	/* Calculate the mod operation and update the stack */
	result = current->next->n % current->n;
	current->next->n = result;
	*stack_head = current->next;
	free(current);
}
