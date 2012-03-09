#include <stdlib.h>
#include <string.h>

char *strrpl(char *str, char *old, char *new)
{
  int old_len;
  int new_len;
  char *new_str = NULL;
  char *f = NULL;
  char *dup = NULL;

  old_len = strlen(old);
  new_len = strlen(new);
  new_str = malloc(sizeof(char) * (strlen(str) + (new_len - old_len)));
  strcpy(new_str, str);
  f = strstr(new_str, old);
  if (new_len < old_len)
    {
      strncpy(f, new, new_len);
      strcpy(&f[new_len], &f[old_len]);
    }
  else if (new_len > old_len)
    {
      dup = strdup(str);
      strncpy(f, new, new_len);
      strcpy(&f[new_len], &dup[strlen(str) - strlen(f) + old_len]);
    }
  else
    strncpy(f, new, new_len);
  return (new_str);
}
