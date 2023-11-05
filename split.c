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
    int max_tokens = 10;

	tokens = malloc(sizeof(char *) * max_tokens);
	if (tokens == NULL)
		return (NULL);

	token = _strtok(str, delimiters);
	while (token != NULL)
	{
		tokens[i++] = token;
        if (i == max_tokens - 1)
        {
            max_tokens *= 2;
            tokens = (char **)realloc(tokens, sizeof(char *) * max_tokens);
            if (tokens == NULL)
                return (NULL);
        }
		token = _strtok(NULL, delimiters);
	}
	tokens[i] = NULL;
	free(token);
	return (tokens);
}
