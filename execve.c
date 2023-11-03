#include "simple_shell.h"

int execute(char **command, char **av)
{
	pid_t child_pid;
    int status, i;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        exit(EXIT_FAILURE);
    }
    
    if (child_pid == 0)
    {
        if (execve(command[0], command, environ) == -1)
        {
            perror(av[0]);
            for(i = 0; command[i]; i++)
            {
                free(command[i]);
                command[i] = NULL;
            }
            exit(EXIT_FAILURE);
        }
        free(command);
    }
    
    else
    {
        waitpid(child_pid, &status, 0);
        for(i = 0; command[i]; i++)
            {
                free(command[i]);
                command[i] = NULL;
            }
        free(command);
    }
    
    return (WEXITSTATUS(status));
}
