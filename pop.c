#include "monty.h"

/**
 * pop_stack - Removes the top element of the stack
 * @stk_head: Pointer to the stack's head
 * @line_count: Line number being processed
 * Return: No return value
 */
void pop_stack(stack_t **stk_head, unsigned int line_count)
{
	stack_t *temp;

	if (*stk_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stk_head);
		exit(EXIT_FAILURE);
	}

	temp = *stk_head;
	*stk_head = temp->next;
	free(temp);
}
