#include "bnc_shell.h"

/**
 * handle_error - A function that handle errors and displays an error message
 * @output: The error message to be displayed
 *
 * Return: Nothing on success
 */

void handle_error(char *output)
{
	perror(output);
}
