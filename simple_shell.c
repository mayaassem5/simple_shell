#include "simple_shell.h"

/**
 * main - Entry point of the program.
 *
 * @ac: Number of command-line arguments.
 * @av: Array of command-line arguments.
 * @env: Array of environment variables.
 *
 * Return: 0 for success.
 */

int main(int ac, char **av, char **env)
{
	size_t n = 0;
	char *line = NULL, *wanted = "PATH";
	ssize_t inp = 0, exec = 0;
	char **split;
	char *pathvar = (_getenv(env, wanted)) ? _getenv(env, wanted) : "";
	char *path = _strdup(pathvar);
	(void)ac;

	interact();
	while (1)
	{
		inp = getline(&line, &n, stdin);
		if (failed(inp))
			break;
		line[inp - 1] = '\0';
		if (_strlen(line) == 0)
		{
			interact();
			continue;
		}
		split = tokenize(line);
		if (!split[0])
			continue;
		if (envcheck(split[0], env))
		{
			interact();
			continue;
		}
		if (!_strcmp(split[0], "exit"))
			break;
		free(path);
		path = _strdup(pathvar);
		exec = execute(split, path, av);
		free(line), line = NULL;
		free(split), split = NULL;
	}
	free(line);
	free(split);
	free(path);
	exit(exec);
}
