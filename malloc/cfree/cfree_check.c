#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include "cfree.h"
#include "cfree_list.h"

extern t_cfree * gl_cfree;
extern int gl_cfree_c;

size_t cfree_check(void)
{
  t_cfree * l;
  size_t leak;
  pid_t pid;
  int c;

  pid = getpid();
  leak = 0;
  c = 0;
  if (gl_cfree) {
    c = cfree_list_count(gl_cfree);
    if (c) {
      printf("==%d==\n", pid);
      printf("==%d== MEMORY LEAK DETECTED ==%d==\n", pid, pid);
      printf("==%d==   Unfree'd malloc: %d\n", pid, c);
      for (l = gl_cfree; l; l = l->next) {
	printf("==%d==     %d B at %p from %s\n", pid, (int)l->size, l->data, l->info);
	leak += l->size;
      }
      printf("==%d==   Total memory lost: %d B in %d missing free\n", pid, (int)leak, gl_cfree_c - (gl_cfree_c - c));
      printf("==%d== MEMORY_LEAK_DETECTED ==%d==\n", pid, pid);
      printf("==%d==\n", pid);
    }
  }
  printf("==%d== cfree: %d malloc, %d free\n", pid, gl_cfree_c, gl_cfree_c - c);
  return (leak);
}
