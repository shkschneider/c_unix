#include "sort.h"

void selection_sort(int *tabl, int size)
{
  int p;

  for (int i = 0; i < (size - 1); i++)
    {
      p = i;
      for (int j = i + 1; j < size; j++)
        if (tabl[p] > tabl[j])
          p = j;
      if (p != i)
        sort_swap(tabl, i, p);
  }
}
