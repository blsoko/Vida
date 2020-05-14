#include "monty.h"

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

void containerBuffer(stack_t **head, char *value, int line)
{
	char *token = strdup(value), limit[] = " \t\n";
	char *temp = token;
	
	token = strtok(temp, limit);
	if (token[0] != '\0' && token[0] == '#')
		return;
	if(_strcmp(token, "push") == 0)
		push(head, value, line);
	else if(_strcmp(token, "pall") == 0) 
		pall(*head);
	else if(_strcmp(token, "pint") == 0)
		pint(*head, line);
	free(temp);
}