#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void fill(int *t, int nb)
{
  int i;
  int c;

  c = 0;
  for (i = 32; nb > 0; c = 0)
    {
      i = 32;
      while (i >= 1)
	{
	  if (nb >= i)
	    {
	      t[c] = 1;
	      nb -= i;
	    }
	  i /= 2;
	  c++;
	}
    }
}

int bindate(void)
{
  time_t clock;
  struct tm *t;

  int h[6] = { 0, 0, 0, 0, 0 };
  int m[6] = { 0, 0, 0, 0, 0 };
  int s[6] = { 0, 0, 0, 0, 0 };

  if ((clock = time(0)) != (time_t)-1)
    if ((t = localtime(&clock)))
      {
	fill(h, t->tm_hour);
	fill(m, t->tm_min);
	fill(s, t->tm_sec);
	printf("%d %d %d %d %d %d h\n", h[0], h[1], h[2], h[3], h[4], h[5]);
	printf("%d %d %d %d %d %d m\n", m[0], m[1], m[2], m[3], m[4], m[5]);
	printf("%d %d %d %d %d %d s\n", s[0], s[1], s[2], s[3], s[4], s[5]);
	return (1);
      }
    else
      fprintf(stderr, "E: could not get locatime");
  else
    fprintf(stderr, "E: could not get time");
  return (0);
}
