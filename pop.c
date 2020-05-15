#include "monty.h"
/**
 * pop - release memory
 *
 * @stack: stack
 * @line_number: number of line
 *
 * Return: nothing
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *vector;

	vector = *stack;
	if (vector == NULL)
	{
		free(release.temp);
		free(release.containerFile);
		free_h(stack);
		fclose(release.openFile);
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*(stack)) = (*(stack))->next;
	free(vector);
}
