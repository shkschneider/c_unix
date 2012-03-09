#ifndef _PREG_MATCH_H_
# define _PREG_MATCH_H_

char **preg_match_all(char *, char *, int *);
char *preg_match_once(char *, char *);
int preg_match(char *, char *);

#endif /* !_PREG_MATCH_H_ */
