#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include "list.h"

extern struct s_cfree * gl_cfree;
extern struct s_cfree_c gl_cfree_c;

/*
  void free(void *ptr);

  free() frees the memory space pointed to by ptr, which must have been returned by a previous call to malloc(), calloc() or realloc().  Otherwise, or if free(ptr) has already been called before, undefined behavior occurs.  If ptr is NULL,  no  operation  is
  performed.

  free() returns no value.
*/

void cfree(void * p)
{
  struct s_cfree * l;
  int pid;

  if (p) {
    pid = getpid();
    for (l = gl_cfree; l; l = l->next) {
      if (l->data == p) {
	free(l->info);
	free(l->data);
	if (l->prev)
	  l->prev->next = l->next;
	else
	  gl_cfree = l->next;
	if (l->next)
	  l->next->prev = l->prev;
	free(l);
	gl_cfree_c.cfree++;
	pid = 0;
      }
    }
    if (pid) {
      printf("==%d==\n", pid);
      printf("==%d== INVALID FREE DETECTED ==%d==\n", pid, pid);
      printf("==%d==   %p points to an un-referenced malloc() or is already free\n", pid, p);
      printf("==%d==   You most likely did not include cfree.h in all sources\n", pid);
      printf("==%d== INVALID FREE DETECTED ==%d==\n", pid, pid);
      printf("==%d==\n", pid);
    }
  }
}
