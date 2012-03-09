#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  char **array = NULL;
  int i;

  // alloc
  {
    // char ** contains argc x (char *)
    array = malloc(sizeof(char *) * argc);
    for (i = 1; i < argc; i++) {
      // alloc'ed space with terminating NULL (char)
      array[i - 1] = strdup(argv[i]);
    }
    // terminal NULL (char *)
    array[i - 1] = NULL;
  }
  // display
  {
    for (i = 0; array[i]; i++)
      printf("%d:%s\n", i, array[i]);
  }
  // free
  {
    for (i = 0; array[i]; i++)
      free(array[i]);
    free(array);
  }
  return (0);
}
