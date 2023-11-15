#include "simple_shell.h"
/**
 * _getenv - gets environment variable.
 * @name: name of variable
 * Return: value
 */
char *_getenv(const char *name)
{
	char *value;
	int len = _strlen((char *)name);
	char **env = environ;

	if (name == NULL || name[len] != '\0')
		return (NULL);

	while (*env != NULL)
	{
		if (_strncmp(*env, (char *)name, len) == 0 && env[0][len] == '=')
		{
			value = _strdup(*env + len + 1);
			return (value);
		}
		env++;
	}
	return (NULL);
}

