int	my_ilen(int nb)
{
  int	len;

  if (!nb)
    return (1);
  len = 0;
  while (nb > 0)
    {
      nb /= 10;
      len++;
    }
  return (len);
}

int	my_ilen_base(int nb, int base)
{
  int	len;

  if (!nb)
    return (1);
  len = 0;
  while (nb > 0)
    {
      nb /= base;
      len++;
    }
  return (len);
}
