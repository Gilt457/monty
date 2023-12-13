#include "monty.h"

/**
 * f_pchar - prints the character at the top of the stack
 * @head: pointer to the stack head
 * @counter: line number
 * Return: nothing
 */
void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *top;

	top = *head;
	if (top == NULL) /* check if stack is empty */
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (top->n < 0 || top->n > 127) /* check if value is a valid ASCII code */
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n); /* print the character */
}
