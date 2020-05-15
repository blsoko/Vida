#include "monty.h"

char *containerFile;

/**
 * free_h - release memory
 *
 * @head: list
 *
 * Return: nothing
*/
void free_h(stack_t **head)
{
	stack_t *vector;

	while ((*(head)) != NULL)
	{
		vector = (*(head));
		(*(head)) = (*(head))->next;
		free(vector);
	}
	free((*(head)));
}

/**
 * main - principal
 *
 * @ac: number of arguments
 * @av: arguments
 *
 * Return: 0
 */
int main(int ac, char *av[])
{
	FILE *openFile;
	unsigned int line = 0;
	size_t containerSize = 320;
	stack_t *head;

	containerFile = malloc(containerSize * sizeof(char));
	if (containerFile == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openFile = fopen(av[1], "r");
	if (openFile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	head = NULL;
	while (getline(&containerFile, &containerSize, openFile) != -1)
	{
		line++;
		containerBuffer(&head, line);
	}
	free(containerFile);
	free_h(&head);
	fclose(openFile);
	return (0);
}
