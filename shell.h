#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/*
 * Header file for the simple shell project.
 * Contains function declarations for handling user input, executing commands,
 * and managing environment variables.
 */

/* Function declarations */
void display_prompt(void);
char *read_input(void);
char **parse_input(char *input);
void execute_cmd(char **args);

void hdle_exit(char **args);
void hdle_env(void);
void hdle_setenv(char **args);
void hdle_unsetenv(char **args);
void hdle_cd(char **args);
void hdle_semicolon(char *input);
void hdle_logical_operators(char *input);
void hdle_alias(char **args);
void hdle_variables(char *input);

#endif /* SHELL_H */

