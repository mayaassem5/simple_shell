#include "simple_shell.h"
/**
 * main - UNIX
 * Return: Always 0 (Success)
 */
int main(void)
{	pid_t child;
	char *line = NULL, **command = NULL;
	size_t l = 0;
	int status = 0, r = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "~$ ", 2);
		if (getline(&line, &l, stdin) == EOF)
			break;
		if (*line == '\n' || *line == '\t')
			continue;
		command = split(line);
		if (command == NULL)
			continue;
		if (built(line, command, &r) == 0)
		{
			child = fork();
			if (child == 0)
			{
				if (execve(findpath(command[0], &r), command, environ) == -1)
				{
					freep(line, command);
					exit(r);
				}
			}
			else
			{
				wait(&status);
				freep(line, command);
				if (WIFEXITED(status))
					r = WEXITSTATUS(status);
			}
			line = NULL;
		}
		else
			freepointer(command);
	}
	free(line);
	exit(status);
}
