#include "simple_shell.h"
/**
 *tokenize - split input
 *
 *@str: string
 *
 *Return: array of words
*/

char **tokenize(char *str)
{
	char *token;
	char **tokens;
	int i = 0;
	char *delimiters = " \t\n";

	tokens = malloc(sizeof(char *) * 100);
	if (tokens == NULL)
		return (NULL);

	token = strtok(str, delimiters);
	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, delimiters);
	}
	tokens[i] = NULL;
	free(token);
	return (tokens);
}
