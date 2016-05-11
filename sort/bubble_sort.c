#include "sort.h"

void bubble_sort(int *tabl, int size)
{
  for (int c = 0; c < (size - 1); c++)
    for (int d = 0; d < (size - c - 1); d++)
      if (tabl[d] > tabl[d + 1])
        sort_swap(tabl, d, d + 1);
}
