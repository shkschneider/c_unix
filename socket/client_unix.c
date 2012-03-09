#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCK_PATH "socket.sock"

int main(void)
{
  int s, t, len;
  struct sockaddr_un remote;
  char str[100];

  if ((s = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
    return (1);
  printf("Establishing connection...\n");
  remote.sun_family = AF_UNIX;
  strcpy(remote.sun_path, SOCK_PATH);
  len = strlen(remote.sun_path) + sizeof(remote.sun_family);
  if (connect(s, (struct sockaddr *)&remote, len) < 0)
    {
      printf("Connection failed.\n");
      return (1);
    }
  printf("Connected.\n\n");
  while (printf("request:  "), fgets(str, 100, stdin), !feof(stdin))
    {
      if (!strcmp(str, "quit\n"))
	break ;
      if (send(s, str, strlen(str), 0) == -1)
	{
	  perror("send");
	  exit(1);
	}
      if ((t = recv(s, str, 100, 0)) > 0)
	{
	  str[t] = '\0';
	  printf("response> %s\n", str);
	}
      else if (t < 0)
	{
	  printf("\nConnection lost.\n");
	  exit(1);
	}
      else
	{
	  printf("\nServer closed connection.\n");
	  exit(1);
	}
    }
  close(s);
  printf("\nConnection closed.\n");
  return (0);
}
