#include "monty.h"

void push(stack_t **head, char *str, int line_number)
{
	stack_t *new_node;
	char *token, limit[] = " \t\n";
	int i, number, j = 0;
	
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, limit);
	token = strtok(NULL, limit);
	while(token[j] != '\0')
	{
		if(token[j] < '0' || token[j] > '9')
		{
			dprintf(STDERR_FILENO, "L%i: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}	
		j++;
	}
	number = atoi(token);
	new_node->n = number;
	new_node->next = (*head);
	new_node->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new_node;
	(*head) = new_node;
}