#include "simple_shell.h"
/**
 * interact - checks if interactive
 *
 * Return: void
 */

void interact(void)
{
    int interactive_mode = isatty(fileno(stdin));

    if (interactive_mode)
        printf("~$ ");

}

/**
 * failed - checks failed
 * 
 * @len: len
 *
 * Return: 1 if failed
 */

int failed(int len)
{
    if (len <= 0)
    {
        if (isatty(STDIN_FILENO))
            printf("~$ ");
            
        return (1);
    }
    return (0);
}
