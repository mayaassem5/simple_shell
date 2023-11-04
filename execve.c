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
	char *tok = strtok(path, ":");
	char final_cmd[1000];
	pid_t child;

	while (tok != NULL)
	{
		final_cmd[0] = '\0';
		if (strchr(line[0], '/') == NULL)
		{
			strcat(final_cmd, tok);
			strcat(final_cmd, "/");
		}

		strcat(final_cmd, line[0]);
		if (access(final_cmd, X_OK) == 0)
		{
			child = fork();
			if (child < 0)
				perror("\n"), exit(99);
			else if (child == 0)
			{
				if (execve(final_cmd, line, av) == -1)
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
	write(STDERR_FILENO, av[0], len(av[0]));
	write(STDERR_FILENO, " 1: ", 4);
	write(STDERR_FILENO, line[0], len(line[0]));
	write(STDERR_FILENO, ": not found\n", 12);
	return (-1);
}
