#include "monty.h"

char *containerFile;
void freeFile(stack_t *head)
{
	stack_t *vector;

	while (head != NULL)
	{
		vector = head;
		head = head->next;
		free(vector);
	}
	free(head);
}
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *token, limit[] = " \t\n";
	int number, j = 0;
	
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(containerFile, limit);
	if (token == NULL)
		return;
	token = strtok(NULL, limit);
	if (token == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while(token[j] != '\0')
	{
		if(token[j] < '0' || token[j] > '9')
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}	
		j++;
	}
	number = atoi(token);
	new_node->n = number;
	new_node->next = (*stack);
	new_node->prev = NULL;
	if ((*stack) != NULL)
		(*stack)->prev = new_node;
	(*stack) = new_node;
}