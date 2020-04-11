#include "library.h"

char **fetch_paths(char **envp)
{
  char *path_string = _getenv(envp, "PATH");
  return (separate_string(path_string, ":"));
}

char *_getenv(char **envp, char *name)
{
  char **envs = envp;
  char *env_var;
  char *name_to_find;

  for (; *envs != NULL; envs++) {
    for (env_var = *envs, name_to_find = name; *env_var == *name_to_find; env_var++) {
      if (*env_var == '=') {
        break;
      }
      name_to_find++;
    }
    if ((*env_var == '=') && (*name_to_find == '\0')) {
      return (env_var + 1);
    }
  }
  return (NULL);
}