#include <stdio.h>
#include <stdlib.h>
#include "bnc_shell.h"

/**
 * bnc_env - A function that prints the current environment variables.
 *
 * This function prints each environment variable on a new line.
 * It uses the 'environ' variable to access the environment.
 */

void bnc_env(void)
{
	/*Access to the environment variables*/
	char **env = environ;

	/*loop through the environment variables*/
	while (*env != NULL)
	{
		printf("%s\n", *env);
	env++;
	}
}

