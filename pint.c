#include "monty.h"
/**
 * pint - release memory
 *
 * @stack: head stack
 * @line_number: number of line
 *
 * Return: nothing
*/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *vector;

	vector = *stack;
	if (vector == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", vector->n);
}
