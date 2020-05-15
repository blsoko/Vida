#include "monty.h"
/**
 * pstr - release memory
 *
 * @stack: stack
 * @line_number: number of line
 *
 * Return: nothing
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *vector;

	vector = *stack;
	(void)line_number;
	while (vector != NULL)
	{
		if (vector->n <= 0 || vector->n > 127)
		{
			break;
		}
		printf("%c", vector->n);
		vector = vector->next;
	}
	printf("\n");
}
