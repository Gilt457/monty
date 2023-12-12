#include "monty.h"

/**
 * print_char_at_top - Prints the character at the top of the stack
 * followed by a new line
 * @stk_head: Pointer to the head of the stack
 * @line_num: Line number in the file
 * Return: No return value
 */
void print_char_at_top(stack_t **stk_head, unsigned int line_num)
{
	stack_t *top;

	top = *stk_head;
	if (!top)
	{
		fprintf(stderr, "L%d: can't print char, stack empty\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stk_head);
		exit(EXIT_FAILURE);
	}
	if (top->n > 127 || top->n < 0)
	{
		fprintf(stderr, "L%d: can't print char, value out of range\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stk_head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}
