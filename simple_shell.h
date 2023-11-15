#ifndef _SHELL_H_
#define _SHELL_H_

#define _GNU_SOURCE

#define CHECK_NULL(x) if (x == NULL) continue;

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <libgen.h>

extern char **environ;
char *_getenv(const char *name);
char *findpath(char *command, int *r);

int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_concat(char *s1, char *s2);
char *_strdup(char *str);
char *_strncpy(char *dest, char *src, int n);

void freep(char *buffer, char **commands);
void freepointer(char **pointer);

unsigned int len(char *s);
char **split(char *str);

int built(char *line, char **command, int *retVal);
void env(char **environ);

void error(char *av, int count, char *command);
void execerror(char *av, int count, char *tmp_command);
void printstr(char *str, int new_line);
int printnum(int n);
int _write(char c);

void _puts(char *str);
int _putchar(char c);

int _PATHstrcmp(const char *s1, const char *s2);
int _strcmp(const char *s1, const char *s2);
#endif

