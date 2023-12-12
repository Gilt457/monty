#include "monty.h"

/**
 * pushNode - Adds a node to the stack
 * @stackHead: Pointer to the head of the stack
 * @lineNumber: Line number
 *
 * Description: This function adds a node to the stack based on the integer
 * provided in the argument.
 */
void pushNode(stack_t **stackHead, unsigned int lineNumber)
{
	int number, i = 0, isNegative = 0;

	if (bus.argument)
	{
		if (bus.argument[0] == '-')
			i++;

		while (bus.argument[i] != '\0')
		{
			if (bus.argument[i] > 57 || bus.argument[i] < 48)
				isNegative = 1;
			i++;
		}

		if (isNegative == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stackHead);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stackHead);
		exit(EXIT_FAILURE);
	}

	number = atoi(bus.argument);

	if (bus.lifo == 0)
		addNode(stackHead, number);
	else
		addQueue(stackHead, number);
}
