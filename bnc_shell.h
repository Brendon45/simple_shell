#ifndef BNC_SHELL_H
#define BNC_SHELL_H

/*Constants for our simple_shell*/

#define MAX_INPUT_SIZE 1024 /*Maximum size for user input buffer*/
#define READ_SIZE 1024 /*Size for reading input incrementally*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>

extern char **environ;

/*Function prototypes for our simple_shell*/

/*The entry point of our shell program*/
int main(void);

/*It executes a command with its arguments*/
int bnc_exec_entry(char **command_args);

/*It reads a line of input from the user*/
char *bnc_read_input(void);

/*It handle erros*/
void handle_error(char *output);

/*It handles the SIGINT signal (Ctrl+C)*/
void sigint_handler(int signal_number);

/*It handles the SIGQUIT signal (Ctrl+\)*/
void sigquit_handler(int signal_number);

/*It handles the SIGTSTP signal (Ctrl+Z)*/
void sigstp_handler(int signal_number);
/*It parses the user input into an array of command arguments*/
char **bnc_parse_input(char *input_string);

/*It frees the memory allocated for an array of strings*/
void tokenized_array(char **str_array);

void bnc_exit(char *user_command);
void bnc_env(void);

#endif /*BNC_SHELL_H*/

