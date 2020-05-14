#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
	if ((*(stack)) == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while ((*(stack)) != NULL)
	{
		printf("%d\n", (*(stack))->n);
		(*(stack)) = (*(stack))->prev;
	}
	
}