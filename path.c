#include "simple_shell.h"
/**
 * findpath - find dir
 *@command: string
 *@r: return
 * Return: the directory
 */
char *findpath(char *command, int *r)
{
	char *path, *toprint, *path_copy, *tok;
	struct stat stats;
	char *current;

	if (command == NULL)
		return (NULL);

	if (stat(command, &stats) == 0)
		return (command);

	path = _getenv("PATH");
	toprint = command;
	command = _concat("/", command);

	path_copy = _strdup(path);
	tok = strtok(path_copy, ":");

	while (tok != NULL)
	{
		current = _concat(tok, command);
		if (stat(current, &stats) == 0)
		{
			free(path_copy);
			return (current);
		}
		free(current);
		tok = strtok(NULL, ":");
	}
	free(path_copy);
	error(path, len(command), toprint);
	printstr(": not found", 0);
	free(command);
	*r = 127;
	return (NULL);
}

