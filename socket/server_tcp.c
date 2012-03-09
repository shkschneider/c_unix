#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define TCP_PORT 4242
#define MAX_CLIENTS 5

int main(void)
{
  int s, s2, t, len, on = 1;
  struct sockaddr_in local, remote;
  char str[100];

  if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    return (1);
  local.sin_family = AF_INET;
  /* bzero(&local, sizeof(local)); /\* BSD *\/ */
  /* memset(&local, 0, sizeof(local)); /\* System-V *\/ */
  local.sin_family = AF_INET;
  local.sin_port = htons(TCP_PORT);
  local.sin_addr.s_addr = htonl(INADDR_ANY);
  if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
    return (1);
  if (setsockopt(s, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof(on)) < 0)
    return (1);
  if (bind(s, (struct sockaddr *)&local, sizeof(local)) < 0)
    return (1);
  if (listen(s, MAX_CLIENTS) < 0)
    return (1);
  printf("Server running.\n");
  while (42)
    {
      int	n;

      printf("Waiting for connection...\n");
      t = sizeof(remote);
      if ((s2 = accept(s, (struct sockaddr *)&remote, &t)) < 0)
	exit(1);
      printf("Connected.\n");
      n = 1;
      while (n > 0)
	{
	  n = recv(s2, str, 100, 0);
	  if (n < 0)
	    perror("recv");
	  else if (n > 0)
	    {
	      str[n] = '\0';
	      printf("< %s", str);
	      if (send(s2, str, n, 0) < 0)
		perror("send");
	      else
		printf("> %s", str);
	    }
	}
      printf("Connection closed by client.\n");
      close(s2);
  }
  printf("Server stoped.\n");
  return (0);
}
