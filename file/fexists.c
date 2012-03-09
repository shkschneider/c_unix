#include <stdio.h>

int fexists(const char *filename)
{
  FILE *f = NULL;

  if ((f = fopen(filename, "r")))
    {
      fclose(f);
      return (1);
    }
  return (0);
}

int main(void)
{
  printf("%d\n", fexists("test"));
  return (0);
}
