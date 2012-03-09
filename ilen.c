int ilen(int nb)
{
  int len;

  if (!nb)
    return (1);
  for (len = 0; nb > 0; len++)
    nb /= 10;
  return (len);
}

int ilen_base(int nb, int base)
{
  int len;

  if (!nb)
    return (1);
  for (len = 0; nb > 0 ; len++)
    nb /= base;
  return (len);
}
