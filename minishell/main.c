#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_ARGUMENTS 10

extern char **environ;

int execute_command(char *command, char *arguments[]) {
    if (strcmp(command, "echo") == 0) {
        // Handle echo command
        int i = 0;
        while (arguments[i] != NULL) {
            printf("%s ", arguments[i]);
            i++;
        }
        printf("\n");
    } else if (strcmp(command, "cd") == 0) {
        // Handle cd command
        if (arguments[0] == NULL) {
            printf("cd: missing directory\n");
        } else if (arguments[1] != NULL) {
            printf("cd: too many arguments\n");
        } else {
            if (chdir(arguments[0]) != 0) {
                printf("cd: %s: No such file or directory\n", arguments[0]);
            }
        }
    } else if (strcmp(command, "pwd") == 0) {
        // Handle pwd command
        if (arguments[0] != NULL) {
            printf("pwd: too many arguments\n");
        } else {
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                printf("%s\n", cwd);
            } else {
                printf("pwd: error retrieving current directory\n");
            }
        }
    } else if (strcmp(command, "export") == 0) {
        // Handle export command
        if (arguments[0] == NULL) {
            printf("export: missing variable name\n");
        } else if (arguments[1] != NULL) {
            printf("export: too many arguments\n");
        } else {
            if (setenv(arguments[0], "", 1) != 0) {
                printf("export: failed to set variable\n");
            }
        }
    } else if (strcmp(command, "unset") == 0) {
        // Handle unset command
        if (arguments[0] == NULL) {
            printf("unset: missing variable name\n");
        } else if (arguments[1] != NULL) {
            printf("unset: too many arguments\n");
        } else {
            if (unsetenv(arguments[0]) != 0) {
                printf("unset: failed to unset variable\n");
            }
        }
    } else if (strcmp(command, "env") == 0) {
        // Handle env command
        char **env = environ;
        while (*env != NULL) {
            printf("%s\n", *env);
            env++;
        }
    } else if (strcmp(command, "exit") == 0) {
        // Handle exit command
        printf("Exiting the shell...\n");
        exit(0);
    } else {
        printf("Command not found: %s\n", command);
    }
    return 0;
}


int parse_input(char *input, char *command, char *arguments[]) {
    char *token = strtok(input, " \t\n");
    int arg_count = 0;

    while (token != NULL) {
        if (arg_count == 0) {
            strcpy(command, token);
        } else {
            arguments[arg_count - 1] = token;
        }
        token = strtok(NULL, " \t\n");
        arg_count++;
    }
    arguments[arg_count - 1] = NULL;

    return arg_count - 1;
}

int main() {
    char *input;
    char command[MAX_ARGUMENTS];
    char *arguments[MAX_ARGUMENTS];

    while (1) {
        input = readline("CustomShell$ ");

        if (input == NULL) {
            break;
        }

        if (strlen(input) > 0) {
            add_history(input);
        }

        int arg_count = parse_input(input, command, arguments);
        if (arg_count > 0) {
            execute_command(command, arguments);
        }

        free(input);
    }

    return 0;
}
