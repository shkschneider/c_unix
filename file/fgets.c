#include <stdio.h>
#include <string.h>

#ifndef MAXLEN
# define MAXLEN	1024
#endif

int	main(void)
{
  FILE	*f;
  char	str[MAXLEN];

  if ((f = fopen("test", "r")))
    {
      fgets(str, MAXLEN, f);
      printf("%s\n", str);
      fclose(f);
    }
  return (0);
}
