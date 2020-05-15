#include "monty.h"
/**
 * swap - release memory
 *
 * @stack: stack
 * @line_number: number of line
 *
 * Return: nothing
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *vector;
	int x = 0;

	vector = *stack;
	vector = vector->next;
	if ((*(stack)) == NULL || vector == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	x = vector->n;
	vector->n = (*(stack))->n;
	(*(stack))->n = x;
}
