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
	unsigned int i, len;

	i = 0;
	while (environ[i])
	{
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
		++i;
	}
}

