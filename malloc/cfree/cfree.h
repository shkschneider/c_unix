#ifndef _CFREE_H_
# define _CFREE_H_

void * cmalloc(size_t, const char *, const char *, const int);

# define malloc(x) cmalloc(x, __FUNCTION__, __FILE__, __LINE__)

void cfree(void *);
size_t cfree_check(void);

# define free(x) cfree(x)

#endif /* !_CFREE_H_ */
