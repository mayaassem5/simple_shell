#include "simple_shell.h"

/**
 * print_env - prints env
 *
 * @env: enviroment
 *
 * Return: void
*/

void print_env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * envcheck - checks env
 *
 * @ag: arg
 * @env: env
 *
 * Return: 1 if env
*/

int envcheck(char *ag, char **env)
{
	if (!_strcmp(ag, "env"))
	{
		print_env(env);
		return (1);
	}
	return (0);
}

/**
 * _getenv - checks env
 *
 * @wanted: wanted
 * @env: env
 *
 * Return: 0
*/

char *_getenv(char **env, char *wanted)
{
	int i, len;

	len = _strlen(wanted);

	while (*env)
	{
		for (i = 0; i < len; i++)
		{
			if (wanted[i] != (*env)[i])
				break;
		}
		if (i == len)
			return (&(*env)[i + 1]);
		env++;
	}
	return (NULL);
}

