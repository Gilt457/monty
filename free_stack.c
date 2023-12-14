#include "monty.h"

/**
 * release_stack - Deallocates a stack_t linked list
 * @stack: Pointer to the head of the stack
 *
 * This function deallocates all nodes of a stack represented
 * as a linked list (stack_t).
 */
void release_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
