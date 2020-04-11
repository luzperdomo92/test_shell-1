#include "library.h"

/**
 * takeInput - function to take user input params.
 *
 * @keep_prompt: it takes the keep_prompt address from main.
 *
 * Return: buffer.
 */
char *takeInput(int *keep_prompt)
{
	size_t buffer_size = BUFF_MAX;
	char *buffer = (char *)malloc(buffer_size * sizeof(char));
	int char_count;

	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	char_count = getline(&buffer, &buffer_size, stdin);
	if (char_count == EOF)
	{
		*keep_prompt = 0;
    write(2, "\n", 1);
	  return (buffer);
	}
	
  if (buffer[char_count - 1] == '\n')
  {
    buffer[char_count - 1] = '\0';
    --char_count;
  }
  if (empty_line(buffer) == 1)
  {
    buffer = NULL;
  }
  return (buffer);
}