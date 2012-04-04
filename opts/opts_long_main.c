#include "opts_long.h"

int main(int argc, char **argv)
{
  int i;

  i = opts_long_parse(argc, argv);
  printf("%c=%d\n", 'a', (int *)opts_long_get('a'));
  printf("%c=%s\n", 'c', (char *)opts_long_get('c'));
  while (i < argc)
    printf ("%s\n", argv[i++]);
  return (0);
}
