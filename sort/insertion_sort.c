void insertion_sort_swap(int *tabl, int n1, int n2)
{
  int tmp;

  tmp = tabl[n1];
  tabl[n1] = tabl[n2];
  tabl[n2] = tmp;
}

void insertion_sort(int *tabl, int size)
{
  int j;
  for (int i = 1; i <= size - 1; i++) {
    j = i;
    while (j > 0 && tabl[j] < tabl[j - 1]) {
      insertion_sort_swap(tabl, j, j - 1);
      j--;
    }
  }
}
