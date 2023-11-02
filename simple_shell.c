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
    char *line = NULL;
    char **command = NULL;
    int state;
    while(1)
    {
        line = read_input();
        command = tokenizer(line);
        state = _execute(command, av);
    }
    
}
