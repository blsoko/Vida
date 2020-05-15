#include "monty.h"
/**
 * pchar - release memory
 *
 * @stack: stack
 * @line_number: number of line
 *
 * Return: nothing
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	int x = 0;

	if ((*(stack)) == NULL)
	{
		free(release.temp);
		free(release.containerFile);
		free_h(stack);
		fclose(release.openFile);
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	x = (*(stack))->n;
	if (x < 0 || x > 255)
	{
		free(release.temp);
		free(release.containerFile);
		free_h(stack);
		fclose(release.openFile);
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", x);
}
