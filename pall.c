#include "monty.h"
/**
 * pall - release memory
 *
 * @stack: stack
 * @line_number: number of line
 *
 * Return: nothing
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *vector;

	vector = *stack;
	(void)line_number;
	while (vector != NULL)
	{
		printf("%d\n", vector->n);
		vector = vector->next;
	}
}
