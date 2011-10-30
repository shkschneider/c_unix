#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

# define SOCK_PATH	"socket"
# define MAX_CLIENTS	5

int			main(void)
{
  int			s, s2, t, len, on = 1;
  struct sockaddr_un	local, remote;
  char			str[100];

  if ((s = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
    return (1);
  local.sun_family = AF_UNIX;
  strcpy(local.sun_path, SOCK_PATH);
  unlink(local.sun_path);
  len = strlen(local.sun_path) + sizeof(local.sun_family);
  if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
    return (1);
  if (setsockopt(s, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof(on)) < 0)
    return (1);
  if (bind(s, (struct sockaddr *)&local, len) < 0)
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
