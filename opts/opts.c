#include "opts.h"

struct option opts_list[] =
  {
    /* IGNORE, no_argument | required_argument, value (keep at 0), short */
    {"", no_argument, 0, 'a'},
    {"", required_argument, 0, 'b'},
    {"", no_argument, 0, 'c'},
    {0, 0, 0}
  };

char *opts_init(void)
{
  char *opts;
  int i;
  int j;

  for (i = 0; opts_list[i].val; i++)
    ;
  opts = malloc(sizeof(char) * ((2 * i) + 1));
  j = 0;
  for (i = 0; opts_list[i].val; i++)
    {
      opts[j++] = opts_list[i].val;
      if (opts_list[i].has_arg == required_argument)
	opts[j++] = ':';
    }
  opts[j] = '\0';
  return (opts);
}

int *opts_get(char c)
{
  int i;

  for (i = 0; opts_list[i].val; i++)
    if (c == opts_list[i].val)
      return (opts_list[i].flag);
  return (NULL);
}

void opts_error(char *opts)
{
  if (strchr(opts, optopt))
    fprintf(stderr, "Option -%c requires an argument.\n", optopt);
  else if (isprint(optopt))
    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
  else
    fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
  exit(1);
}

int opts_parse(int argc, char **argv)
{
  char *opts;
  int c;
  int i;

  opts = opts_init();
  opterr = 0;
  while ((c = getopt(argc, argv, opts)) != -1)
    {
      if (c == '?')
	opts_error(opts);
      else
	{
	  for (i = 0; opts_list[i].val; i++)
	    if (c == opts_list[i].val)
	      {
		if (opts_list[i].has_arg == no_argument)
		  opts_list[i].flag = (int *)1;
		else
		  opts_list[i].flag = (int *)optarg;
		break ;
	      }
	}
    }
  free(opts);
  return (optind);
}
