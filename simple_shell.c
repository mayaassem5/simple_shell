#include "simple_shell.h"
#include <stdio.h>

/*
*main - simple shell main func.
*
*@ac: arg counts
*@av: arg vectors
*
*Return: 0 always
*/

int main(int ac, char **av)
{
    char *ptr;
    char **inp;
    int state;
    ptr = NULL;
    inp = NULL;
    state = 0;
    (void)ac; (void)av;

    while(1)
    {
        ptr = read_in();
        if (!ptr)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return state;
        }
        inp = split(ptr);
        if (!inp)
            continue;

       state = execute(inp, av);
    }

    return 0;
}
