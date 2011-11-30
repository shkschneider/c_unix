#ifndef _OPTS_LONG_H_
# define _OPTS_LONG_H_

# include <stdio.h>
# include <stdlib.h>
# include <getopt.h>

int *opts_long_get(char);
/* options are declared in a struct option in opts_long.c */
int opts_long_parse(int, char **);

#endif /* !_OPTS_LONG_H_ */
