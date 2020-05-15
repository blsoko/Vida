#include "monty.h"
/**
 * mod - release memory
 *
 * @stack: stack
 * @line_number: number of line
 *
 * Return: nothing
*/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *vector;
	int x = 0;

	vector = *stack;
	x = vector->n;
	if (x == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*(stack)) = (*(stack))->next;
	if ((*(stack)) == NULL || vector == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*(stack))->n = (*(stack))->n % x;
	free(vector);
}
