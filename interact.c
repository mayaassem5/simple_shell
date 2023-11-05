#include "simple_shell.h"
/**
 * interact - checks if interactive
 *
 * Return: void
 */

void interact(void)
{
	int interactive_mode = isatty(fileno(stdin));
	char *prompt = "~$ ";

	if (interactive_mode)
		write(STDOUT_FILENO, prompt, _strlen(prompt));
}

/**
 * failed - checks failed
 *
 * @len: len
 *
 * Return: 1 if failed
 */

int failed(int len)
{
	char *prompt = "~$ ";

	if (len <= 0)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		return (1);
	}
	return (0);
}

