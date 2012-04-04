#include "opts.h"

int main(int argc, char **argv)
{
  int i;

  i = opts_parse(argc, argv);
  printf("%c=%d\n", 'a', (int *)opts_get('a'));
  printf("%c=%s\n", 'b', (char *)opts_get('b'));
  printf("%c=%d\n", 'c', (int *)opts_get('c'));
  while (i < argc)
    printf("Non-option argument %s\n", argv[i++]);
  return (0);
}
