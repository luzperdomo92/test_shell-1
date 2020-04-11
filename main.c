#include "library.h"
/**
 * main - main of the code for Simple Shell functions.
 *
 * Return: Always 0.
 */
int main(int argc, char **argv, char **envp)
{
	int keep_prompt;
  char **paths = fetch_paths(envp);

	keep_prompt = 1;
	while (keep_prompt)
	{
		handle_prompt(&keep_prompt, paths);
	}

  free(paths);
	return (0);
}