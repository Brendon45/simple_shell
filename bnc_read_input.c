#include "bnc_shell.h"

/**
* bnc_read_input - A function that reads input from the user
*
* Return: The input string entered by the user
*/

char *bnc_read_input(void)
{
	char *user_input = NULL;
	size_t input_size = 0;

	if (isatty(STDIN_FILENO))
	/*The prompt will be displayed in an interactive mode for entering a command*/
		write(STDOUT_FILENO, "MyShell$ ", 9);

	if (getline(&user_input, &input_size, stdin) == -1)
	{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "\n", 1);
		}
			free(user_input);
			return (NULL);
		}
	return (user_input);
}
