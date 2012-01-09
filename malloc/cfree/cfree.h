#ifndef _CFREE_H_
# define _CFREE_H_

void * cmalloc(size_t, const char *, const char *, const int);
void * crealloc(void *, size_t, const char *, const char *, const int);
void * ccalloc(size_t, size_t, const char *, const char *, const int);
void cfree(void *);
size_t cfree_check(void);

# define malloc(x) cmalloc(x, __FUNCTION__, __FILE__, __LINE__)
# define realloc(x) crealloc(x, __FUNCTION__, __FILE__, __LINE__)
# define calloc(x) ccalloc(x, __FUNCTION__, __FILE__, __LINE__)
# define free(x) cfree(x)

#endif /* !_CFREE_H_ */
