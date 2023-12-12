#include "monty.h"

/**
 * execute_opcode - Executes the opcode
 * @content: Line content containing the opcode
 * @stack: Pointer to the head of the stack
 * @counter: Line counter
 * @file: Pointer to the monty file
 *
 * Return: No explicit return value
 */
int execute_opcode(char *content, stack_t **stack,
	unsigned int counter, FILE *file)
{
	instruction_t opcodes[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop}, {"swap", f_swap}, {"add", f_add},
		{"nop", f_nop}, {"sub", f_sub}, {"div", f_div},
		{"mul", f_mul}, {"mod", f_mod}, {"pchar", f_pchar},
		{"pstr", f_pstr}, {"rotl", f_rotl}, {"rotr", f_rotr},
		{"queue", f_queue}, {"stack", f_stack},
		{NULL, NULL}
	};
	unsigned int index = 0;
	char *opcode;

	opcode = strtok(content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);

	bus.arg = strtok(NULL, " \n\t");
	while (opcodes[index].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[index].opcode) == 0)
		{
			opcodes[index].f(stack, counter);
			return (0);
		}
		index++;
	}

	if (opcode && opcodes[index].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			counter, opcode);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
