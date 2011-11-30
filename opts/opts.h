#ifndef _OPTS_H_
# define _OPTS_H_

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <getopt.h>

int *opts_get(char);
/* options are declared in a struct option in opts.c */
int opts_parse(int, char **);

#endif /* !_OPTS_H_ */
