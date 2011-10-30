#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

# define TCP_PORT	4242

int			main(void)
{
  int			s, t, len;
  struct sockaddr_in	remote;
  char			str[100];
  struct hostent	*he;

  if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    return (1);
  printf("Establishing connection...\n");
  /* bzero(&remote, sizeof(remote)); /\* BSD *\/ */
  /* memset(&remote, 0, sizeof(remote)); /\* System-V *\/ */
  remote.sin_family = AF_INET;
  remote.sin_port = htons(TCP_PORT);
  if (!(he = gethostbyname("localhost")))
    return (1);
  memcpy(&remote.sin_addr, he->h_addr_list[0], he->h_length);
  if (connect(s, (struct sockaddr *)&remote, sizeof(struct sockaddr_in)) < 0)
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
