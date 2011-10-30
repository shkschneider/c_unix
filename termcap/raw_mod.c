#include <termios.h>

struct termios	oldtermios;

int	raw_mod(void)
{
  struct termios	newtermios;

  if (tcgetattr(0, &oldtermios) < 0)
    return (0);
  newtermios = oldtermios;
  newtermios.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
  newtermios.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
  newtermios.c_cflag &= ~(CSIZE | PARENB);
  newtermios.c_cflag |= CS8;
  newtermios.c_oflag &= ~(OPOST);
  newtermios.c_cc[VMIN] = 1;
  newtermios.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSAFLUSH, &newtermios) < 0)
    return (0);
  return (1);
}

#include <ctype.h>
#include <string.h>
#include <stdio.h>

#include "raw_mod.h"

int	main(void)
{
  char	c[8];
  int	t;

  printf("ESC stops the program.\n");
  if (!raw_mod())
    return (1);
  memset(c, '\0', 8);
  while (read(0, &c, 8) > 0)
    {
      t = c[0] + c[1] + c[2] + c[3] + c[4] + c[5] + c[6] + c[7];
      if (t == K_ESCAPE)
	break ;
      if (isprint(c[0]))
	printf("%.3d '%c'\n\r", t, c[0]);
      else
	printf("%.3d\n\r", t);
      memset(c, '\0', 8);
    }
  if (tcsetattr(0, TCSAFLUSH, &oldtermios) < 0)
    return (1);
  return (0);
}
