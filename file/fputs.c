#include <stdio.h>

int	main(void)
{
  FILE	*f;

  if ((f = fopen("test", "a")))
    {
      fputs("test\n", f);
      fclose(f);
    }
  return (0);
}
