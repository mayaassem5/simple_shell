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

char *_strtok(char *str, char *delimiters)
{
    char *x = NULL;
    char *token = NULL;

    if (str != NULL) {
        x = str;
    }

    if (x == NULL) {
        return (NULL);
    }

    token = x + _strspn(x, delimiters);

    if (*token == '\0') {
        x = NULL;
        return (NULL);
    }

    x = token + (_strspn(token, delimiters));

    if (*x != '\0') {
        *x = '\0';
        x++;
    }

    return (token);
}
