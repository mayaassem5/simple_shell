#include "simple_shell.h"

/**
 * print_env - prints env
 * @env: enviroment
 *
 * Return: void
 */

void print_env(char **env)
{
    int i = 0;

    while (env[i] != NULL)
    {
	write(STDOUT_FILENO, env[i], strlen(env[i]));
	write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}

/**
 * check_env - checks env
 * 
 * @ar: arg
 * @env: env
 *
 * Return: 1 if env
 */

int envcheck(char *ag, char **env)
{
    if (!strcmp(ag, "env"))
    {
        print_env(env);
        return (1);
    }
    return (0);
}
