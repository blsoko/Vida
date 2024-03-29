#include "monty.h"

freet release;

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
	unsigned int line = 0;
	size_t containerSize = 320;
	stack_t *head;

	release.containerFile = malloc(containerSize * sizeof(char));
	if (release.containerFile == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (ac != 2)
	{
		free(release.containerFile);
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	release.openFile = fopen(av[1], "r");
	if (release.openFile == NULL)
	{
		free(release.containerFile);
		free(release.openFile);
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	head = NULL;
	while (getline(&release.containerFile, &containerSize, release.openFile)
	!= -1)
	{
		line++;
		containerBuffer(&head, line);
	}
	free(release.containerFile);
	free_h(&head);
	fclose(release.openFile);
	return (0);
}
