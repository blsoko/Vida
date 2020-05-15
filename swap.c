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
	if ((*(stack)) == NULL || vector == NULL || vector->next == NULL)
	{
		free(release.temp);
		free(release.containerFile);
		free_h(stack);
		fclose(release.openFile);
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	vector = vector->next;
	x = vector->n;
	vector->n = (*(stack))->n;
	(*(stack))->n = x;
}
