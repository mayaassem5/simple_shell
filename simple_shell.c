#include "simple_shell.h"
/**
 * main - UNIX
 * Return: Always 0 (Success)
 */
int main(void)
{
	pid_t child;
	char *line = NULL, **command = NULL, *path;
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
		CHECK_NULL(command);
		child = fork();
		if ((built(line, command, &r) == 0) && child == 0)
		{
			path = findpath(command[0], &r);
			if (path == NULL && (freep(line, command), 1))
				exit(EXIT_FAILURE);
			if (execve(path, command, environ) == -1 && (freep(line, command), 1))
				exit(r);
		}
		else if (freepointer(command), 1)
			continue;
		wait(&status);
		freep(line, command);
		if (WIFEXITED(status))
			r = WEXITSTATUS(status);
		line = NULL;
	}
	free(line);
	exit(status);
}

