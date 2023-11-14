#include <signal.h>
#include "bnc_shell.h"
#include <unistd.h>

/**
* sigquit_handler - A function that handles the SIGQUIT signal (Ctrl+\)
* @signal_number: ...
* Return: Nothing on (success)
*/

void sigquit_handler(int signal_number)
{
	(void)signal_number;
	/*It checks if the standard input is a terminal*/
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "\n", 1);
	}
}

