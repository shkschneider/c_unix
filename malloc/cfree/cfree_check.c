#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include "cfree.h"
#include "cfree_list.h"

extern t_cfree * gl_cfree;

size_t cfree_check(void) {
  t_cfree * l;
  size_t leak;
  pid_t pid;
  int c;

  if (!gl_cfree)
    return (0);
  pid = getpid();
  leak = 0;
  c = cfree_list_count(gl_cfree);
  if (c) {
    printf("==%d==\n", pid);
    printf("==%d== MEMORY LEAK DETECTED ==%d==\n", pid, pid);
    printf("==%d==   Unfree'd malloc: %d\n", pid, c);
    for (l = gl_cfree; l; l = l->next) {
      printf("==%d==     %do at %p from %s\n", pid, (int)l->size, l->data, l->info);
      leak += l->size;
    }
    printf("==%d==   Total memory lost: %do\n", pid, (int)leak);
    printf("==%d== MEMORY_LEAK_DETECTED ==%d==\n", pid, pid);
    printf("==%d==\n", pid);
  }
  return (leak);
}
