#include <stdlib.h>
#include <stdio.h>

void *xmalloc(size_t sz)
{
  void * p = NULL;

  p = malloc(sz);
  if (p == NULL)
    {
      if (sz > 0)
	{
	  fprintf(stderr, "E: malloc() failed");
	  exit(1);
	}
      // else: empty but valid malloc
    }
  return (p);
}

int test(char **p, size_t sz)
{
  *p = xmalloc(sz);
  return (42);
}

int main(void)
{
  char *p1 = NULL, *p2 = NULL, *p3 = NULL;
  int i = 0;

  // regular alloc
  p1 = xmalloc(42);
  printf("i=%d, p1=%p\n", i, p1);
  // empty but valid alloc
  p2 = xmalloc(0);
  printf("i=%d, p2=%p\n", i, p2);
  // tricky alloc
  i = test(&p3, 42);
  printf("i=%d, p3=%p\n", i, p3);
  return (0);
}
