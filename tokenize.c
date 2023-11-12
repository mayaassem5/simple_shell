#include "simple_shell.h"

/**
 * len - calculate the lenght
 *@s: char pointer
 * Return: length of pointer
 */
unsigned int len(char *s)
{
	unsigned int count = 0, i = 0, f = 0;
	char *s_copy = _strdup(s);

	if (s_copy == NULL)
		return (0);

	s_copy[_strlen(s_copy) - 1] = '\0';

	while (s[i] != '\0')
	{
		if (s[i] != ' ')
			f = 1;
		if ((f && s[i + 1] == ' ') || (f && s[i + 1] == '\0'))
		{
			++count;
			f = 0;
		}
		++i;
	}
	free(s_copy);
	return (count);
}

/**
 * split - separate line in tokens
 * @str: command line
 * Return: char
 */
char **split(char *str)
{
	char deli[] = " \t\n\r";
	char **command, *tok;
	unsigned int leng, i;

	str[_strlen(str) - 1] = '\0';
	leng = len(str);
	if (leng == 0)
		return ('\0');

	command = malloc((sizeof(char *) * (leng + 1)));
	if (command == NULL)
	{
		freepointer(command);
		return (NULL);
	}

	i = 0;
	tok = strtok(str, deli);
	if (tok == NULL)
	{
		freepointer(command);
		return (NULL);
	}

	while (tok != NULL)
	{
		command[i] = malloc(_strlen(tok) + 1);
		if (command[i] == NULL)
		{
			freepointer(command);
			return (NULL);
		}
		_strncpy(command[i], tok, _strlen(tok) + 1);
		tok = strtok(NULL, deli);
		++i;
	}
	command[i] = NULL;
	return (command);
}

