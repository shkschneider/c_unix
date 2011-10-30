#include <stdio.h>

int	main(void)
{
  FILE	*f;

  if ((f = fopen("test", "r+")))
    {
      /* ... */
      fclose(f);
    }
  return (0);
}
