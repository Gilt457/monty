#include "monty.h"
/**
 * f_pstr - prints the string from the top of the stack to the standard output
 * @head: pointer to the head of the stack
 * @counter: line number of the instruction
 * Return: nothing
 */
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;

	(void)counter; /* unused parameter */
	h = *head; /* assign head to h */
	while (h) /* loop through the stack */
	{
		if (h->n > 127 || h->n <= 0) /* check if the value is printable */
		{
			break; /* exit the loop */
		}
		printf("%c", h->n); /* print the character */
		h = h->next; /* move to the next node */
	}
	printf("\n"); /* print a new line */
}
