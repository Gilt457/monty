#include "monty.h"

/**
 * free_stack - deallocates a stack_t list
 * @stack: pointer to the head of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
