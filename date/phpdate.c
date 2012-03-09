#include <time.h>

#ifndef _PHP_DATE_
# define _PHP_DATE_
# define DATE_YEAR	'y'
# define DATE_MONTH	'M'
# define DATE_DAY	'd'
# define DATE_HOUR	'h'
# define DATE_MIN	'm'
# define DATE_SEC	's'
#endif /* !_PHP_DATE_ */

int phpdate(char c)
{
  time_t clock;
  struct tm *t = NULL;
  int rt;

  rt = 0;
  clock = time(0);
  if ((t = localtime(&clock)))
    {
      if (c == DATE_YEAR)
        rt = (t->tm_year + 1900);
      else if (c == DATE_MONTH)
        rt = t->tm_mon;
      else if (c == DATE_DAY)
        rt = t->tm_mday;
      else if (c == DATE_HOUR)
        rt = t->tm_hour;
      else if (c == DATE_MIN)
        rt = t->tm_min;
      else if (c == DATE_SEC)
        rt = t->tm_sec;
    }
  return (rt);
}
