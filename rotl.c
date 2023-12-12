#include "monty.h"

/**
 * rotate_stack_left - Rotates the stack elements to the top (left)
 * @stack: Double pointer to the head of the stack
 * @line_num: Line number being executed
 * Description: The top element of the stack becomes the last one
 * Return: No return value (void)
 */
void rotate_stack_left(stack_t **stack, __attribute__((unused)) unsigned int line_num)
{
	stack_t *temp_head = *stack, *auxiliary;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	auxiliary = (*stack)->next;
	auxiliary->prev = NULL;

	while (temp_head->next != NULL)
		temp_head = temp_head->next;

	temp_head->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp_head;
	(*stack) = auxiliary;
}
