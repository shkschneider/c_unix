/* echo "banana" | ./a.out sed 's/a/o/g' */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
  pid_t	pid;
  int	pc[2];
  int	cp[2];
  char	ch;

  if (pipe(pc) < 0)
    return (1);
  if (pipe(cp) < 0)
    return (1);
  if ((pid = fork()) < 0)
    return (1);
  else if (pid == 0)
    {
      close(1);
      dup(cp[1]);
      close(0);
      dup(pc[0]);
      close(pc[1]);
      close(cp[0]);
      execvp(argv[1], argv + 1);
      exit(1);
    }
  else if (pid > 0)
    {
      while (read(0, &ch, 1) > 0)
	{
	  write(pc[1], &ch, 1);
	  write(1, &ch, 1);
	}
      close(pc[1]);
      close(cp[1]);
      while (read(cp[0], &ch, 1) == 1)
	write(1, &ch, 1);
    }
  return (0);
}
