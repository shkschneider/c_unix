#include "opts_long.h"

struct option opts_long_list[] =
  {
    /* long, no_argument | required_argument, value (keep at 0), short */
    {"verbose", no_argument, 0, 'v'},
    {"brief", no_argument, 0, 'b'},
    {"add", no_argument, 0, 'a'},
    {"delete", required_argument, 0, 'd'},
    {"create", required_argument, 0, 'c'},
    {"file", required_argument, 0, 'f'},
    {0, 0, 0, 0}
  };

char *opts_long_init(void)
{
  char *opts;
  int i;
  int j;

  for (i = 0; opts_long_list[i].name; i++)
    ;
  opts = malloc(sizeof(char) * ((2 * i) + 1));
  j = 0;
  for (i = 0; opts_long_list[i].name; i++)
    {
      opts[j++] = opts_long_list[i].val;
      if (opts_long_list[i].has_arg == required_argument)
	opts[j++] = ':';
    }
  opts[j] = '\0';
  return (opts);
}

int *opts_long_get(char c)
{
  int i;

  for (i = 0; opts_long_list[i].name; i++)
    if (opts_long_list[i].val == c)
      return (opts_long_list[i].flag);
  return (NULL);
}

int opts_long_parse(int argc, char **argv)
{
  char *opts;
  int i;
  int c;

  opts = opts_long_init();
  while ((c = getopt_long(argc, argv, opts, opts_long_list, NULL)) != -1)
    {
      if (c == '?')
	break ;
      else
	{
	  for (i = 0; opts_long_list[i].name; i++)
	    if (opts_long_list[i].val == c)
	      {
		if (opts_long_list[i].has_arg == no_argument)
		  opts_long_list[i].flag = (int *)1;
		else
		  opts_long_list[i].flag = (int *)optarg;
		break ;
	      }
	}
    }
  free(opts);
  return (optind);
}
