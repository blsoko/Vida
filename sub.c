#include "monty.h"
/**
 * sub - release memory
 *
 * @stack: stack
 * @line_number: number of line
 *
 * Return: nothing
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *vector;
	int x = 0;

	vector = *stack;
	(*(stack)) = (*(stack))->next;
	if ((*(stack)) == NULL || vector == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	x = vector->n;
	(*(stack))->n = (*(stack))->n - x;
	free(vector);
}