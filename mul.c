#include "monty.h"

/**
 * multiply_top_two - multiplies the top two elements of the stack.
 * @stack_head: pointer to the stack's head
 * @line_num: line number in the file
 * Return: no return value
 */
void multiply_top_two(stack_t **stack_head, unsigned int line_num)
{
	stack_t *current;
	int stack_length = 0, result;

	current = *stack_head;

	while (current)
	{
		current = current->next;
		stack_length++;
	}

	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't multiply, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	current = *stack_head;
	result = current->next->n * current->n; /* Multiply top two elements */
	current->next->n = result;
	*stack_head = current->next;
	free(current);
}
