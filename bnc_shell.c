#include <stdio.h>
#include "bnc_shell.h"
#include <stdlib.h>
void juryt(void);

/**
 * main - This function serves as the entry point of the shell program
 *
 * Return: EXIT_SUCCESS only.
 */

int main(void)
{
	/*Declarations of the main shell*/
	char *user_input;
	int shell_status;
	char **command_args;

	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	signal(SIGTSTP, sigstp_handler);

	do {
	user_input = bnc_read_input(); /*reads user input*/
	/*Check for end of file (EOF)*/
	if (!user_input || !*user_input)
	{
	break;
	}

	command_args = bnc_parse_input(user_input);
	if (!command_args || !*command_args)
	{
		free(user_input);
		tokenized_array(command_args);
		continue;
	}
	if (strcmp(command_args[0], "exit") == 0)
	{
		bnc_exit(user_input);
		free(user_input);
		tokenized_array(command_args);
	break; /*it should exit the loop if the command is "exit"*/
	}
	else if (strcmp(command_args[0], "env") == 0)
	{
		bnc_env();
		free(user_input);
		tokenized_array(command_args);
		continue;
	}
	/*Executes the input*/
	shell_status = bnc_exec_entry(command_args);

	free(user_input); /*frees the user input*/
	tokenized_array(command_args);
	shell_status = 1;
	} while (shell_status);

	return (EXIT_SUCCESS);
}
