#include <stdlib.h>

void	do_fusion_sort(int *tabl, int *tabl_cpy, int size)
{
  int	n;
  int	i;
  int	j;
  int	mid;
  int	*tabl_cpy2;

  mid = size / 2;
  if (mid > 1)
    do_fusion_sort(tabl_cpy, tabl, mid);
  if (size-mid > 1)
    do_fusion_sort(tabl_cpy + mid, tabl + mid, size - mid);
  tabl_cpy2 = tabl_cpy + mid;
  for (n = 0, i = 0, j = 0; i < mid && j < size - mid; n++)
    tabl[n] = (tabl_cpy[i] < tabl_cpy2[j]) ? tabl_cpy[i++] : tabl_cpy2[j++];
  while (i < mid)
    tabl[n++] = tabl_cpy[i++];
  while (j < size - mid)
    tabl[n++] = tabl_cpy2[j++];
}

void	fusion_sort(int *tabl, int size)
{
  int	*tabl_cpy;
  int	i;

  tabl_cpy = malloc(sizeof(int) * size);
  for (i = 0; i < size; i++)
    tabl_cpy[i] = tabl[i];
  do_fusion_sort(tabl, tabl_cpy, size);
  free(tabl_cpy);
}
