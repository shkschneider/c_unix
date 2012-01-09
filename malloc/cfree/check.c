#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include "cfree.h"
#include "list.h"

extern struct s_cfree * gl_cfree;
extern struct s_cfree_c gl_cfree_c;

#define ALLOC (gl_cfree_c.cmalloc)
#define FREE (gl_cfree_c.cfree)

size_t cfree_check(void)
{
  struct s_cfree * l;
  int leaks;
  size_t bytes;
  pid_t pid;

  pid = getpid();
  leaks = ALLOC - FREE;
  bytes = 0;
  if (gl_cfree) {
    printf("==%d==\n", pid);
    printf("==%d== MEMORY LEAK DETECTED ==%d==\n", pid, pid);
    printf("==%d==   Unfree'd malloc: %d\n", pid, leaks);
    for (l = gl_cfree; l; l = l->next) {
      printf("==%d==     %d B at %p from %s\n", pid, (int)l->size, l->data, l->info);
      bytes += l->size;
    }
    printf("==%d==   Total memory lost: %d B in %d missing free\n", pid, (int)bytes, leaks);
    printf("==%d== MEMORY_LEAK_DETECTED ==%d==\n", pid, pid);
    printf("==%d==\n", pid);
  }
  printf("==%d== cfree: %d alloc, %d free\n", pid, ALLOC, FREE);
  return (bytes);
}
