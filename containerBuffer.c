#include "monty.h"
/**
 * _strcmp - release memory
 *
 * @s1: string1
 * @s2: string2
 *
 * Return: diferrence string1 - string2
*/
int _strcmp(char *s1, char *s2)
{
	int i, rtn = 0;

	for (i = 0; s1[i] || s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			rtn = s1[i] - s2[i];
			break;
		}
	}
	return (rtn);
}
/**
 * containerBuffer - release memory
 *
 * @head: stack
 * @line: number of line
 *
 * Return: nothing
*/
void containerBuffer(stack_t **head, unsigned int line)
{
	char *token = strdup(release.containerFile), limit[] = " \t\n";
	char *temp = token;
	int j = 0, flag = 0;

	instruction_t seg[] = {{"push", push}, {"pall", pall},
	{"pint", pint}, {"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
	{"sub", sub}, {"div", div1}, {"mul", mul}, {"mod", mod},
	{"pchar", pchar}, {'\0', NULL}};
	token = strtok(token, limit);
	if (token == NULL)
		return;
	else if (token[0] != '\0' && token[0] == '#')
		return;
	while (seg[j].opcode != '\0') /*structrure elements iterator*/
	{
		if (_strcmp(token, seg[j].opcode) == 0)
		{
			flag = 1;
			(seg[j].f)(head, line);
			break;
		}
		j++;
	}
	if (flag == 0)
	{
		free(temp);
		free(release.containerFile);
		free_h(head);
		fclose(release.openFile);
		fprintf(stderr, "L%u: unknown instruction <opcode>\n", line);
		exit(EXIT_FAILURE);
	}
	free(temp);
}
