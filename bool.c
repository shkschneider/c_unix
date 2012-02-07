typedef enum bool
  {
    TRUE = 1,
    FALSE = 0
  } bool;

#include <stdio.h>

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
