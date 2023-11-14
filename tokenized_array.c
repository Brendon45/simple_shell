#include "bnc_shell.h"

/**
 * tokenized_array - A function that releases the memory allocated for an array
 * @str_array: ...
 *
 * Return: nothing (on success)
 */

void tokenized_array(char **str_array)
{
	int index;

	if (str_array)
	{
	for (index = 0; str_array[index]; index++)
	{
		/*It frees each string*/
		free(str_array[index]);
	}
	/*It frees the array of strings*/
	free(str_array);
	}
}
