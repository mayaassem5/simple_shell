#include "simple_shell.h"

char *read_in(void)
{
    char *ptr = NULL;
    size_t len = 0;
    int read;

    printf("~$ ");
    read = getline(&ptr, &len, stdin);

    if(read == -1)
    {
        free(ptr);
        perror("ERROR");
        exit(EXIT_FAILURE);
    }

    return (ptr);
}
