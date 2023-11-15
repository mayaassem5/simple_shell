#include "simple_shell.h"
/**
 * _getenv - gets environment variable.
 * @name: name of variable
 * Return: value
 */
char *_getenv(const char *name)
{
	int len = _strlen((char *)name);
	char **env = environ;

	if (name == NULL)
		return (NULL);

	while (*env != NULL)
	{
		if (_strncmp(*env, (char *)name, len) == 0 && env[0][len] == '=')
			return (*env + len + 1);
		env++;
	}
	return (NULL);
}

