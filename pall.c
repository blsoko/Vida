#include "monty.h"

void pall(const stack_t *head)
{
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}