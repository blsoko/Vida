#include "monty.h"
/**
 * mul - release memory
 *
 * @stack: stack
 * @line_number: number of line
 *
 * Return: nothing
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *vector;
	int x = 0;

	vector = *stack;
	if ((*(stack)) == NULL || vector == NULL || (*(stack))->next == NULL)
	{
		free(release.temp);
		free(release.containerFile);
		free_h(stack);
		fclose(release.openFile);
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*(stack)) = (*(stack))->next;
	x = vector->n;
	(*(stack))->n = (*(stack))->n * x;
	free(vector);
}
