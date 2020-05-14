#include "monty.h"

void free_h(stack_t *head)
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

int main(int ac, char *av[])
{
	FILE *openFile;
	char *containerFile;
	int line = 0;
	size_t containerSize = 320;
	stack_t *head;

	containerFile = malloc(containerSize * sizeof(char));
	if (containerFile == NULL)
		exit(EXIT_FAILURE);
	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(1);
	}
	openFile = fopen(av[1], "r");
	if (openFile == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	head = NULL;
	while (getline(&containerFile, &containerSize, openFile) != -1)
	{
		line++;
		containerBuffer(&head, containerFile, line);
	}
	free(containerFile);
	free_h(head);
	fclose(openFile);
	return (0);
}