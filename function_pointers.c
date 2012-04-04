#include <stdlib.h>
#include <stdio.h>

int test(void)
{
  return (1);
}

int (*test2(void))(void)
{
  return test;
}

int plus(int n1, int n2)
{
  return (n1 + n2);
}

int minus(int n1, int n2)
{
  return (n1 - n2);
}

int times(int n1, int n2)
{
  return (n1 * n2);
}

int divide(int n1, int n2)
{
  return (n1 / n2);
}

int main(void)
{
  int (*f)(void);
  int (*ff)(void);
  int (*ffff[4])(int, int) = { plus, minus, times, divide };

  f = test;
  printf("%d\n", f());
  ff = test2();
  printf("%d\n", ff());
  printf("%d\n", ffff[1](10, 5));
  return (0);
}
