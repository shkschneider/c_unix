#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
  pid_t pid;
  int pair[2];
  char buf[10];

  if (socketpair(AF_UNIX, SOCK_STREAM, 0, pair) < 0)
    return (1);
  send(pair[0], "foo", 4, 0);
  recv(pair[1], buf, 4, 0);
  printf("Received '%s' from pair[1] after putting 'foo' into pair[0]\n", buf);
  if ((pid = fork()) < 0)
    return (1);
  if (pid == 0)
    {
      send(pair[1], "bar", 4, 0);
      exit(0);
    }
  else
    {
      recv(pair[0], buf, 4, 0);
      printf("Parent: received '%s' from pair[0] after child put 'bar' into pair[1]\n", buf);
      waitpid(pid, 0, 0);
    }
  return (0);
}
