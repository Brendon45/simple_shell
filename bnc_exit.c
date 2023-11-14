#include "bnc_shell.h"

/**
 * bnc_exit - A function that gracefully exits the shell program
 * @user_command: The user input to be processed
 *
 * Return: Nothing on (success).
 */

void bnc_exit(char *user_command)
{
	if (strcmp(user_command, "exit") == 0)
	{
		printf("Exiting the bnc_shell program\n");
	exit(0);
	}
}

