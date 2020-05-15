#include "monty.h"
/**
 * div1 - release memory
 *
 * @stack: stack
 * @line_number: number of line
 *
 * Return: nothing
*/
void div1(stack_t **stack, unsigned int line_number)
{
	stack_t *vector;
	int x = 0;

	vector = *stack;
	(*(stack)) = (*(stack))->next;
	if ((*(stack)) == NULL || vector == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	x = vector->n;
	if (x == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free(vector);
		exit(EXIT_FAILURE);
	}
	(*(stack))->n = (*(stack))->n / x;
	free(vector);
}
