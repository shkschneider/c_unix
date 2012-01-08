#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include "cfree_list.h"

t_cfree * gl_cfree = NULL;
int gl_cfree_c = 0;

void cfree(void * p)
{
  t_cfree * l;
  int pid;

  if (gl_cfree && p)
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
	return ;
      }
    }
  pid = getpid();
  printf("==%d==\n", pid);
  printf("==%d== INVALID FREE DETECTED ==%d==\n", pid, pid);
  printf("==%d==   %p points to an un-referenced malloc()\n", pid, p);
  printf("==%d==   You most likely did not include cfree.h in all sources\n", pid);
  printf("==%d== INVALID FREE DETECTED ==%d==\n", pid, pid);
  printf("==%d==\n", pid);
}
