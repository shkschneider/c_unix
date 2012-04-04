#!/bin/sh
cat $0 | sed -n '1,2d;p' >/tmp/cs.$$.c && gcc -Wall -o /tmp/cs.$$ /tmp/cs.$$.c && /tmp/cs.$$ $*; rm -f /tmp/cs.$$*; exit

/*
 * From <http://guillaume.salagnac.free.fr/monoeuvre/geek/scripts/>
 */

#include <stdio.h>

int main(int argc, char **argv)
{
  int index;

  printf("Hello world!\n");
  for (index = 0; index < argc; index++)
    printf("argv[%d]='%s'\n", index, argv[index]);
  return (0);
}
