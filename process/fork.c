#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void work(char *p)
{
  if (!strcmp(p, "child"))
    printf("%s: #%d ##%d\n", p, getpid(), getppid());
  else
    printf("%s: #%d\n", p, getpid());
  fflush(stdout);
}

int main(void)
{
  pid_t	pid;

  if ((pid = fork()) < 0)
    return (1);
  else if (pid == 0)
    {
      work("child");
      exit(0);
    }
  else
    {
      work("parent (before waitpid)");
      waitpid(pid, 0, 0);
      work("parent (after waitpid)");
    }
  return (0);
}
