#include "simple_shell.h"
/**
 * findpath - find dir
 *@command: string
 *@r: return
 * Return: the directory
 */
char *findpath(char *command, int *r)
{
	char *path, *toprint;
	struct stat stats;
	char *current, *tok;

	if (stat(command, &stats) == 0)
		return (command);

	path = _getenv("PATH");
	tok = strtok(path, ":");
	toprint = command;
	command = _concat("/", command);

	while (tok != NULL)
	{
		current = _concat(tok, command);
		if (stat(current, &stats) == 0)
		{
			free(command);
			return (current);
		}
		free(current);
		tok = strtok(NULL, ":");
	}

	error(path, len(command), toprint);
	printstr(": not found", 0);
	free(command);
	*r = 127;
	return (NULL);
}