#include <signal.h>
#include "bnc_shell.h"
#include <unistd.h>

/**
* sigint_handler - This function should handle the SIGINT signal (Ctrl+C)
* @signal_number: A signal number (unused but documented).
*
* Return: Nothing on (success).
*/

void sigint_handler(int signal_number)
{
	(void)signal_number;
	/*It checks if the standard input is a terminal*/
	if (isatty(STDIN_FILENO))
	{
	/*It prints a newline to the terminal */
		write(STDOUT_FILENO, "\n($) ", 5);
	}
}
