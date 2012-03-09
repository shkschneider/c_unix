#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  // do not forget the terminating NULL (char *)
  char *array[] = {"one", "two", "three", NULL};
  int i;

  for (i = 0; array[i]; i++)
    printf("%d:%s\n", i, array[i]);
  return (0);
}
