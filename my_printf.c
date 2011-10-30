#include <stdarg.h>
#include <elf.h>

#define HEXA_MIN	"0123456789abcdef"
#define HEXA_CAP	"0123456789ABCDEF"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  if (str)
    for (i = 0; str[i]; i++)
      my_putchar(str[i]);
  else
    my_putstr("(null)");
}

void		my_put_hexa(unsigned int nb, char *base)
{
  unsigned int	beg;
  unsigned int	end;

  end = nb % 16;
  beg = (nb - end) / 16;
  if (beg)
    my_put_hexa(beg, base);
  my_putchar(base[end]);
}

void	my_put_nbr(int nb)
{
  int	beg;
  int	end;

  end = nb % 10;
  beg = (nb - end) / 10;
  if (beg)
    my_put_nbr(beg);
  my_putchar('0' + end);
}

void		my_put_unbr(uint32_t nb)
{
  uint32_t	diviz;

  if ((int)nb == -1)
    my_putstr("4294967295");
  else
    {
      diviz = 1;
      while ((diviz * 10) < nb)
        diviz *= 10;
      while (diviz)
        {
          my_putchar((char)((int)'0' + (int)(nb / diviz)));
          nb -= ((nb / diviz) * diviz);
          diviz /= 10;
        }
    }
}

void		my_printf(char *all, ...)
{
  va_list	args;
  int		i;

  va_start(args, all);
  i = 0;
  while (all[i])
    {
      if (all[i] == '%')
        {
          if (all[i + 1] == 's')
            my_putstr(va_arg(args, char *));
          else if (all[i + 1] == 'd' || all[i + 1] == 'i')
            my_put_nbr(va_arg(args, int));
          else if (all[i + 1] == 'c')
            my_putchar((char)va_arg(args, int));
          else if (all[i + 1] == 'x' || all[i + 1] == 'X')
            my_put_hexa(va_arg(args, unsigned int), (all[i + 1] == 'x' ? HEXA_MIN : HEXA_CAP));
          else if (all[i + 1] == 'u')
            my_put_unbr(va_arg(args, unsigned int));
          else
            my_putchar(all[i + 1]);
          i++;
        }
      else
        my_putchar(all[i]);
      i++;
    }
  va_end(args);
}

int	main()
{
  my_printf("%s %d %i %c %x %X %u test\n", "test", 1, 2, 'c', 42, 42, 12887238732);
  my_printf("test %d %d %d %d\n", 64, 128, 512, 1024);
  return (0);
}
