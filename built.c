#include "simple_shell.h"
/**
 *built - execute built-ins
 *@line: command line
 *@command: separate tokens
 *@retVal: return value of exit
 * Return: void
 */

int built(char *line, char **command, int *retVal)
{
	char *bexit = "exit", *b = "env";

	if (_strncmp(command[0], bexit, 4) == 0)
	{
		freep(line, command);
		exit(*retVal);
	}
	else if (_strncmp(command[0], b, 3) == 0)
	{
		env(environ);
		return (1);
	}
	else
		return (0);
}

/**
 * env - prints the environment
 * @environ: environ
 *
 * Return: void
 */
void env(char **environ)
{
	int i;

	for (i = 0; environ[i]; i++)
		puts(environ[i]);
}
/**
 * _puts - prints a string
 * @str: string to print
 */
void _puts(char *str)
{
	int c;

	for (c = 0; str[c] != '\0'; c++)
		_putchar(str[c]);
	_putchar('\n');
}
/**
 * _putchar - prints a character
 * @c: character to print
 *
 * Return: return value of write syscall
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

