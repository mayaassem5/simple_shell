#include "simple_shell.h"

/**
 * execute - execute
 * @line: string
 * @path: path
 * @av: args
 *
 * Return: void
 */

int execute(char **line, char *path, char **av)
{
	int status;
	char *x = strtok(path, ":");
	char command[1000];
	pid_t child;

	while (x != NULL)
	{
		command[0] = '\0';
		if (_strchr(line[0], '/') == NULL)
		{
			strcat(command, x);
			strcat(command, "/");
		}

		strcat(command, line[0]);
		if (access(command, X_OK) == 0)
		{
			child = fork();
			if (child < 0)
				perror("\n"), exit(99);
			else if (child == 0)
			{
				if (execve(command, line, av) == -1)
					perror(av[0]), exit(99);
			}
			else
			{
				wait(&status);
				interact();
				if (WIFEXITED(status))
					return (WEXITSTATUS(status));
			}
		}
		x = strtok(NULL, ":");
	}
	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, " 1: ", 4);
	write(STDERR_FILENO, line[0], _strlen(line[0]));
	write(STDERR_FILENO, ": not found\n", 12);
	return (-1);
}
