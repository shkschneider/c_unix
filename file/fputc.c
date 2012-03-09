#include <stdio.h>

int main(void)
{
  FILE *f = NULL;

  if ((f = fopen("test", "a")))
    {
      fputc('*', f);
      fclose(f);
    }
  return (0);
}
