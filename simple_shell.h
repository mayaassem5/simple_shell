#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void interact(void);
int failed(int len);

void print_env(char **env);
int envcheck(char *ag, char **env);
char *_getenv(char **env, char *wanted);

int execute(char **line, char *path, char **av);

char **tokenize(char *str);

int _strlen(char *s);
char *_strchr(char *s, char c);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dwest, char *src);

unsigned int _strspn(char *s, char *accept);
char *_strtok(char *str, char *delimiters);
char *_strpbrk(char *s, char *accept);

#endif
