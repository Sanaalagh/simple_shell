#include "shell.h"
#include <unistd.h>
/* Handle the exit built-in command */
void hdle_exit(char **args) {
    free(args);
    exit(EXIT_SUCCESS);
}
/* Handle the env built-in command */
void hdle_env(void) {
	extern char **environ;
    char **environ_var = environ;
    while (*environ_var != NULL) {
	    write(STDOUT_FILENO, *environ_var, strlen(*environ_var));
	    write(STDOUT_FILENO, "\n", 1);
	    environ_var++;
    }
}
/*Handle the setenv built-in command */
void hdle_setenv(char **args) {
    if (args[1] != NULL && args[2] != NULL && args[3] == NULL) {
        if (setenv(args[1], args[2], 1) != 0) {
            perror("hsh");
        }
    } else {
        write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 30);
    }
}
/* Handle the unsetenv built-in command */
void hdle_unsetenv(char **args) {
    if (args[1] != NULL && args[2] == NULL) {
        if (unsetenv(args[1]) != 0) {
            perror("shell");
        }
    } else {
        write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
    }
}
/*it Changes the current working directory */
void hdle_cd(char **args) {
    if (args[1] == NULL) {
        chdir(getenv("HOME"));
    } else if (args[2] == NULL) {
        if (chdir(args[1]) != 0) {
            perror("hsh");
        }
    } else {
        write(STDERR_FILENO, "Usage: cd [DIRECTORY]\n", 23);
    }
}
