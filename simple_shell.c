#include "simple_shell.h"
#include <stdio.h>

/*
*main - simple shell main func.
*
*@ac: arg counts
*@av: arg vectors
*@env: env arg
*
*Return: 0 always
*/

int main(int ac, char **av, char **env)
{
    size_t n = 0;
    char *line = NULL;
    ssize_t inp = 0, exec = 0;
    char **split;
    char *pathvar = (getenv("PATH")) ? getenv("PATH") : "";
    char *path = strdup(pathvar);
    (void)ac;

    interact();
    while(1)
    {
        inp = getline(&line, &n, stdin);
        if (failed(inp))
            break;

        line[inp - 1] = '\0';
        if (strlen(line) == 0)
        {
            interact();
            continue;
        }

        split = tokenize(line);
        if (!split[0])
            continue;
        if (envcheck(split[0], env))
        {
            interact();
            continue;
        }
        if (!strcmp(split[0], "exit"))
            break;
        free(path);
        path = strdup(pathvar);
        exec = execute(split, path, av);
        free(line), line = NULL;
        free(split), split = NULL;
    }
    free(line);
    free(split);
    free(path);
    exit(exec);
}
