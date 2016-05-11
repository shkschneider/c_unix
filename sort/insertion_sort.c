#include "sort.h"

void insertion_sort(int *tabl, int size)
{
  for (int i = 1; i <= size - 1; i++)
    for (int j = i; j > 0 && tabl[j] < tabl[j - 1]; j--)
      sort_swap(tabl, j, j - 1);
}
