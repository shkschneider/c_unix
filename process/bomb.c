#include <unistd.h>

int	main(void)
{
  while (42)
    fork();
  return (0);
}
