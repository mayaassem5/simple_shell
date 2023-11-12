#include "simple_shell.h"
/**
 * error - Entry point
 *@av: command
 *@count: tokens
 *@command: char string
 * Return: Always 0 (Success)
 */
void error(char *av, int count, char *command)
{
	printstr(av, 1);
	printstr(": ", 1);
	printnum(count);
	printstr(": ", 1);
	printstr(command, 1);
}
/**
 * execerror - Entry point
 *@av: command[0]
 *@count: count tokens
 *@tmp: command
 * Return: void
 */
void execerror(char *av, int count, char *tmp)
{
	error(av, count, tmp);
	printstr(": ", 1);
	perror("");
	exit(1);
}

/**
 * printstr - Entry point
 *@str: char string
 *@line: string
 * Return: void
 */
void printstr(char *str, int line)
{
	int i;

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		write(STDOUT_FILENO, &str[i], 1);
	if (line == 0)
		write(STDOUT_FILENO, "\n", 1);
}

/**
 * printnum - Entry point
 *@n: int
 * Return: len
 */
int printnum(int n)
{
	int div, len;
	unsigned int num;

	div = 1;
	len = 0;
	num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _write('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}

/**
 * _write - Entry
 *@c: character
 * Return: Always 0
 */
int _write(char c)
{
	return (write(1, &c, 1));
}

