#include "shell.h"
/* Main file for the simple shell project.
 * Implements basic shell functionalities like user input, command execution,
 * and environment variable management.
 */
int main(void) {
    char *input;
    char **args;

    while (1) {
        display_prompt();
        input = read_input();
        /* Check for alias expansion and replace */
        hdle_alias(&input);
	/* Check for variable expansion and replace */
        hdle_variables(input);

        /* Handle command separator (;) */
        hdle_semicolon(input);

        /* Handle logical operators (&& and ||)
        hdle_logical_operators(*input);*/
        /* Parse input into arguments */
        args = parse_input(input);

        if (args[0] != NULL) {
            if (strcmp(args[0], "exit") == 0) {
                hdle_exit(args);
            } else if (strcmp(args[0], "env") == 0) {
                hdle_env();
            } else if (strcmp(args[0], "setenv") == 0) {
                hdle_setenv(args);
            } else if (strcmp(args[0], "unsetenv") == 0) {
                hdle_unsetenv(args);
            } else if (strcmp(args[0], "cd") == 0) {
                hdle_cd(args);
            } else {
                execute_cmd(args);
            }
        }

        free(input);
        free(args);
    }

    return(0);
}
