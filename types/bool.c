#include <stdio.h>
#include "bool.h"

int main(void)
{
  bool b;

  b = FALSE;
  if (!b)
    printf("false\n");
  else
    printf("true\n");
  return (0);
}
