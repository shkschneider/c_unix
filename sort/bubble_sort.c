void bubble_sort_swap(int *tabl, int n1, int n2)
{
  int tmp;

  tmp = tabl[n1];
  tabl[n1] = tabl[n2];
  tabl[n2] = tmp;
}

void bubble_sort(int *tabl, int size)
{
  for (int c = 0; c < (size - 1); c++) {
    for (int d = 0; d < (size - c - 1); d++) {
      if (tabl[d] > tabl[d + 1]) {
        bubble_sort_swap(tabl, d, d + 1);
      }
    }
  }
}
