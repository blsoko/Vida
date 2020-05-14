#include "monty.h"

void pint(stack_t *head, int line)
{
	if (head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	while (head != NULL)
	{
		head = head->next;
	}
	printf("%d\n", head->n);
}