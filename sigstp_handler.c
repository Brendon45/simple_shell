#include <signal.h>
#include "bnc_shell.h"
#include <unistd.h>

/**
* sigstp_handler - Handle the SIGTSTP signal (Ctrl+Z)
* @signal_number: A signal num (unused but documented).
*
* Return: Nothing (on success).
*/

void sigstp_handler(int signal_number)
{
	(void)signal_number;
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "\n($) ", 5);
	}
}

