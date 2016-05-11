void selection_sort_swap(int *tabl, int n1, int n2)
{
  int tmp;

  tmp = tabl[n1];
  tabl[n1] = tabl[n2];
  tabl[n2] = tmp;
}

void selection_sort(int *tabl, int size)
{
  int p = 0;
  for (int i = 0; i < (size - 1); i++) {
    p = i;
    for (int j = i + 1; j < size; j++) {
      if (tabl[p] > tabl[j]) {
        p = j;
      }
    }
    if (p != i) {
      selection_sort_swap(tabl, i, p);
    }
  }
}
