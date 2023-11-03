#ifndef _SHELL_
#define _SHELL_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *read_in(void);
char **split(char *str);
int execute(char **command, char **av);

#endif
