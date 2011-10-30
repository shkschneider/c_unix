#include <stdio.h>

int	main(void)
{
  FILE	*f;
  char	c;

  if ((f = fopen("test", "r")))
    {
      c = fgetc(f);
      printf("%c\n", c);
      fclose(f);
    }
  return (0);
}
