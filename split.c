#include "simple_shell.h"

char **split(char *str) {
    char **tokens = NULL;
    int token_count = 0, i = 0;
    char *token = NULL; 
    char *tmp = NULL;
    char delimiters[] = " \t\n";

    if (!str)
        return (NULL);

    tmp = strdup(str);
    token = strtok(tmp, delimiters);
    if (token == NULL)
    {
        free(str);
        free(tmp);
        return (NULL);
    }

    while (token)
    {
        token_count++;
        token = strtok(NULL, delimiters);
    }
    free(tmp);
    tmp = NULL;

    tokens = malloc(sizeof(char *) * (token_count + 1));
    if (!tokens)
    {
        free(tokens);
        return (NULL);
    }
    token = strtok(str, delimiters);
    while(token)
    {
        tokens[i] = strdup(token);
        token = strtok(NULL, delimiters);
        i++;
    }
    
    free(str);
    tokens[i] = NULL;
    return (tokens);
}
