#include <stdio.h>

int main(void)
{
  FILE *f = NULL;

  if ((f = fopen("test", "r+")))
    {
      /* ... */
      fclose(f);
    }
  return (0);
}
