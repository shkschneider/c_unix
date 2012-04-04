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
