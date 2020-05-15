#include "monty.h"

/**
 * freeFile - release memory
 *
 * @head: stack
 *
 * Return: nothing
*/
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
/**
 * push - release memory
 *
 * @stack: stack
 * @line_number: number of line
 *
 * Return: nothing
*/
void push(stack_t **stack, unsigned int line_number)
{
	char *token, limit[] = " \t\n";
	int number, j = 0;
	stack_t *new_node;

	token = strtok(release.containerFile, limit);
	if (token == NULL)
		return;
	token = strtok(NULL, limit);
	if (token == NULL)
	{
		free(release.temp);
		free(release.containerFile);
		free_h(stack);
		fclose(release.openFile);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (token[j] != '\0')
	{
		if ((token[j] < '0' || token[j] > '9') && token[j] != '-')
		{
			free(release.temp);
			free(release.containerFile);
			free_h(stack);
			fclose(release.openFile);
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		j++;	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);	}
	number = atoi(token);
	new_node->n = number;
	new_node->next = (*stack);
	new_node->prev = NULL;
	if ((*stack) != NULL)
		(*stack)->prev = new_node;
	(*stack) = new_node;	}
