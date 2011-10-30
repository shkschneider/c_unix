#include <stdio.h>
#include <string.h>

void	clear_buffer()
{
  int c;

  c = 0;
  while (c != '\n' && c != EOF)
    c = getchar();
}

int	get_line(char *str, int len)
{
  char	*p;

  if (fgets(str, len, stdin))
    if ((p = strchr(str, '\n')))
      {
	*p = '\0';
	return (1);
      }
  clear_buffer();
  return (0);
}
