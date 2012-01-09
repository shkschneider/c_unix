#ifndef _CFREE_H_
# define _CFREE_H_

void * cmalloc(size_t, const char *, const char *, const int);
void * crealloc(void *, size_t, const char *, const char *, const int);
void * ccalloc(size_t, size_t, const char *, const char *, const int);
void cfree(void *);
size_t cfree_check(void);

#endif /* !_CFREE_H_ */
