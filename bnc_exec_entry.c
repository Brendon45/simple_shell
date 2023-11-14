#include "bnc_shell.h"

/**
 * bnc_exec_entry - A function that executes the given command
 * @command_args: Command arguments
 *
 * Return: 1 on failure and 0 on success
 */

int bnc_exec_entry(char **command_args)
{
	int process_status;
	pid_t child_process_id; /*child_pid*/

	child_process_id = fork();

	if (child_process_id == -1)
	{
		handle_error("fork");
		return (1); /*On failure*/
	}

	if (child_process_id == 0)
	{
		if (execve(command_args[0], command_args, NULL) == -1)
	{
		handle_error("execve");
		exit(EXIT_FAILURE);
	}
	}
	else
	{
		/*The code is executed in the parent process */
		waitpid(child_process_id, &process_status, WUNTRACED);
	return (0); /*On success*/
	}

	return (1); /*On failure*/
}
