#include "simple_shell.h"
/**
 * _strspn - gets the length of a prefix substring.
 * @s: initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, boolea;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		boolea = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				boolea = 0;
				break;
			}
		}
		if (boolea == 1)
			break;
	}
	return (i);
}

/**
 * _strtok - Tokinize
 * @str: initial segment.
 * @delimiters: delimiters
 * Return: 0 always
 */
char *_strtok(char *str, char *delimiters)
{
	static char *nextToken = NULL;
	char *token;

	if (str != NULL)
		nextToken = str;

	if (nextToken == NULL)
		return (NULL);

	nextToken += _strspn(nextToken, delimiters);

	if (*nextToken == '\0')
	{
		nextToken = NULL;
		return (NULL);
	}

	token = nextToken;
	nextToken = _strpbrk(nextToken, delimiters);

	if (nextToken != NULL)
	{
		*nextToken = '\0';
		nextToken++;
	}

	return (token);
}

/**
 * _strpbrk - searches a string for any of a set of bytes.
 * @s: first string.
 * @accept: second string.
 * Return: a pointer to the byte in s that matches one of the
 * bytes in accept, or NULL if no such byte is found.
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
				return (s + i);
		}
	}
	return ('\0');
}
