#include "shell.h"

/**
 * main - Main entry point for the simple shell project.
 * Implements basic shell functionalities like user input, command execution,
 * and environment variable management.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *input;
	char **args;

	while (1)
	{
		display_prompt();
		input = read_input();
		hdle_alias(&input);
		hdle_variables(input);
		hdle_semicolon(input);
		args = parse_input(input);
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
				hdle_exit(args);
			else if (strcmp(args[0], "env") == 0)
				hdle_env();
			else if (strcmp(args[0], "setenv") == 0)
				hdle_setenv(args);
			else if (strcmp(args[0], "unsetenv") == 0)
				hdle_unsetenv(args);
			else if (strcmp(args[0], "cd") == 0)
				hdle_cd(args);
			else
				execute_cmd(args);
		}
		free(input);
		free(args);
	}
	return (0);
}
