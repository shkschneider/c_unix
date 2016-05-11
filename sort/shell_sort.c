void shell_sort_swap(int *tabl, int n1, int n2)
{
  int tmp;

  tmp = tabl[n1];
  tabl[n1] = tabl[n2];
  tabl[n2] = tmp;
}

void shell_sort(int *tabl, int size) {
  for (int i = size / 2; i > 0; i /= 2) {
    for (int j = i; j < size; j++) {
      for (int k = j - i; k >= 0; k -= i) {
        if (tabl[k + i] >= tabl[k]) {
          break;
        }
        else {
          shell_sort_swap(tabl, k, k + i);
        }
      }
    }
  }
}
