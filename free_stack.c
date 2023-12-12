#include "monty.h"

/**
 * free_stack - Returns a doubly linked list
 * @stack_head: Head of the stack
 */
void free_stack(stack_t *stack_head)
{
	stack_t *temp_ptr;

	temp_ptr = stack_head;
	while (stack_head)
	{
		temp_ptr = stack_head->next;
		free(stack_head);
		stack_head = temp_ptr;
	}
}
