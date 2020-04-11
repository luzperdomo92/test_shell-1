#include "library.h"

/**
 * execute_comand - function that execute the paramants
 * type from user
 * @params: string to be read and execute.
 * Return: No Return.
 */
void execute_comand(char **params, char **paths)
{
  char *comand;
	pid_t child_pid;
	int status;

  	if (*params == NULL)
	{
		return;
	}

  comand = (char *)malloc(BUFF_MAX * sizeof(char));

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		exit(1);
	}
	if (child_pid == 0)
	{
    _strncpy(comand, params[0], _strlen(params[0]));
    attach_path(comand, paths);
		if (execve(comand, params, NULL) == -1)
		{
			perror("Error:");
		}
		exit(0);
	}
	else /* parent process*/
	{
		wait(&status);
    free(comand);
		NEW_LINE;
	}
}


void attach_path(char *comand, char **paths)
{
	int index, cmd_file_d;
  char *cmd_with_path;

  if(paths == NULL)
  {
    return;
  }

  cmd_with_path = (char *)malloc(BUFF_MAX * sizeof(char));

	for(index = 0; paths[index] != NULL; index++) {
		_strncpy(cmd_with_path, paths[index], _strlen(paths[index]));
		_strncat(cmd_with_path, "/", 1);
    _strncat(cmd_with_path, comand, _strlen(comand));
    cmd_file_d = open(cmd_with_path, O_RDONLY);

		if(cmd_file_d > 0) {
			_strncpy(comand, cmd_with_path, _strlen(cmd_with_path));
      free(cmd_with_path);
			close(cmd_file_d);
			return;
		}
    strClear(cmd_with_path, BUFF_MAX);
	}

  free(cmd_with_path);
	return;
}