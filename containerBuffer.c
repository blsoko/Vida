#include "monty.h"
char *containerFile;
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

void containerBuffer(stack_t **head, unsigned int line)
{
	char *token = strdup(containerFile), limit[] = " \t\n";
	char *temp = token;
	int j = 0;
	
	instruction_t seg[] = {{"push", push}, {"pall", pall},
	{"pint", pint}, {'\0', NULL}};
	token = strtok(temp, limit);
	if (token[0] != '\0' && token[0] == '#')
		return;
	while (seg[j].opcode != '\0') /*structrure elements iterator*/
	{
		if (_strcmp(token, seg[j].opcode) == 0)
		{
			(seg[j].f)(head, line);
			break;
		}
		j++;
	}
	free(temp);
}