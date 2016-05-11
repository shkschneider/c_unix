#include <stdlib.h>

void radix_sort(int *tabl, int size)
{
  int b[size];
  int m = 0;
  int exp = 1;

  for (int i = 0; i < size; i++)
    if (tabl[i] > m)
      m = tabl[i];
  while (m / exp > 0)
    {
      int box[10] = { 0 };
      for (int i = 0; i < size; i++)
        box[tabl[i] / exp % 10]++;
      for (int i = 1; i < 10; i++)
        box[i] += box[i - 1];
      for (int i = size - 1; i >= 0; i--)
        b[--box[tabl[i] / exp % 10]] = tabl[i];
      for (int i = 0; i < size; i++)
        tabl[i] = b[i];
      exp *= 10;
    }
}
