#include "library.h"

/**
 * prompt - start of prompt.
 *
 * Return: No Return.
 */
void prompt(void)
{
	write(STDOUT, "($) ", 5);
}

/**
 * handle_prompt - Function to print the pronpt, get the command and execute.
 * @keep_prompt: variable with true value
 * Return: No Return, free.
 */
void handle_prompt(int *keep_prompt, char **paths)
{
	char *buffer;
	char **params;

	prompt();
	buffer = takeInput(keep_prompt);
	/*special cases (exit EOF)*/
	params = fill_params(buffer);

	execute_comand(params, paths);
	free(buffer);
	free(params);
}

/**
 * fill_params - take params from the buffer
 * @buffer: string that the user type
 * Return: params separated by an empty space.
 */
char **fill_params(char *buffer)
{
  return (separate_string(buffer, " "));
}