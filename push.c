#include "monty.h"
/**
 * f_push - adds a node to the stack (LIFO) or queue (FIFO)
 * @head: pointer to the head of the stack or queue
 * @counter: line number of the instruction
 * Return: nothing
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg) /* check if argument exists */
	{
		if (bus.arg[0] == '-') /* check for negative sign */
			j++;
		for (; bus.arg[j] != '\0'; j++) /* loop through argument */
		{
			if (bus.arg[j] > '9' || bus.arg[j] < '0') /* check for non-digit */
				flag = 1; /* set flag to 1 */
		}
		if (flag == 1) /* if flag is 1, print error and exit */
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else /* if no argument, print error and exit */
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg); /* convert argument to integer */
	if (bus.lifi == 0) /* if lifi is 0, add node to stack */
		addnode(head, n);
	else /* if lifi is 1, add node to queue */
		addqueue(head, n);
}
