#include "shell.h"

void display_prompt(void) {
    write(STDERR_FILENO,"$ ", 2);
}

char *read_input(void) {
    char *input = NULL;
    size_t len = 0;
    getline(&input, &len, stdin);
    return (input);
}

char **parse_input(char *input) {
    /* Implement your parsing logic here */
    /* For simplicity, split the input by spaces */
    char **args = malloc(sizeof(char *) * 2);
    args[0] = strtok(input, " \n");
    args[1] = NULL;
    return (args);
}

void execute_cmd(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        /* Child process */
        if (execvp(args[0], args) == -1) {
            perror("hsh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("hsh");
    } else {
        /* Parent process */
	    waitpid(pid, &status, WUNTRACED);
    }
}
