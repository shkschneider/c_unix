#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define UDP_PORT 4242

int main(void)
{
  int s, t, len, on = 1;
  struct sockaddr_in local, remote;
  char str[100];

  if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    return (1);
  local.sin_family = AF_INET;
  /* bzero(&local, sizeof(local)); /\* BSD *\/ */
  /* memset(&local, 0, sizeof(local)); /\* System-V *\/ */
  local.sin_family = AF_INET;
  local.sin_port = htons(UDP_PORT);
  local.sin_addr.s_addr = inet_addr("127.0.0.1");
  if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
    return (1);
  if (setsockopt(s, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof(on)) < 0)
    return (1);
  if (bind(s, (struct sockaddr *)&local, sizeof(local)) < 0)
    return (1);
  printf("Server running.\n");
  while (42)
    {
      int	n;

      t = sizeof(remote);
      n = 1;
      while (n > 0)
	{
	  n = recvfrom(s, str, 100, 0, (struct sockaddr *)&remote, &t);
	  if (n < 0)
	    perror("recvfrom");
	  else if (n > 0)
	    {
	      str[n] = '\0';
	      printf("< %s", str);
	      if (sendto(s, str, n, 0, (struct sockaddr *)&remote, sizeof(remote)) < 0)
		perror("sendto");
	      else
		printf("> %s", str);
	    }
	}
      printf("Connection closed by client.\n");
  }
  close(s);
  printf("Server stoped.\n");
  return (0);
}
