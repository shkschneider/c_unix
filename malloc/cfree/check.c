#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include "core.h"
#include "list.h"

extern struct s_cfree * gl_cfree;
extern struct s_cfree_c gl_cfree_c;

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
    printf("==%d== MEMORY LEAK DETECTED\n", pid);
    printf("==%d==   Unfree'd alloc: %d\n", pid, leaks);
    for (l = gl_cfree; l; l = l->next) {
      printf("==%d==     %d B at %p from %s\n", pid, (int)l->size, l->data, l->info);
      bytes += l->size;
    }
    printf("==%d==   Total memory lost: %d B in %d missing free\n", pid, (int)bytes, leaks);
    printf("==%d== MEMORY_LEAK_DETECTED\n", pid);
    printf("==%d==\n", pid);
  } else {
    printf("==%d== No memory leaks found\n", pid);
  }
  printf("==%d== %d alloc (%d malloc, %d realloc, %d calloc), %d free\n", pid, ALLOC, MALLOC, REALLOC, CALLOC, FREE);
  return (bytes);
}
