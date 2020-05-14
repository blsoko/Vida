#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	while ((*(stack)) != NULL)
	{
		printf("%d\n", (*(stack))->n);
		(*(stack)) = (*(stack))->next;
	}
}