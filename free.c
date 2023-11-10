#include "simple_shell.h"
/**
 * freepointer - Entry point
 *@d: double
 * Return: void
 */
void freepointer(char **d)
{
	unsigned int i = 0;

	if (d == NULL)
		return;

	while (d[i])
	{
		free(d[i]);
		++i;
	}

	if (d[i] == NULL)
		free(d[i]);

	free(d);
}

/**
 * freep - Entry point
 *@buffer: pointer
 *@commands: double pointer
 * Return: void
 */
void freep(char *buffer, char **commands)
{
	free(buffer);
	freepointer(commands);
}