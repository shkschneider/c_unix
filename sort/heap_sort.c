void heap_sort_swap(int *tabl, int n1, int n2)
{
  int tmp;

  tmp = tabl[n1];
  tabl[n1] = tabl[n2];
  tabl[n2] = tmp;
}

void do_heap_sort(int *tabl, int n, int k, int tabl_size)
{
  int i;
  int j;

  while (tabl_size--)
    {
      heap_sort_swap(tabl, 0, tabl_size);
      for (n = 0; (i = (2 * n) + 1) < tabl_size; n = k)
        {
	  j = i + 1;
	  if (j < tabl_size && tabl[i] < tabl[j])
	    k = j;
	  else
	    k = i;
	  if (tabl[n] < tabl[k])
	    heap_sort_swap(tabl, n, k);
	  else
	    break ;
        }
    }
}

void heap_sort(int *tabl, int size)
{
  int n;
  int k;
  int tabl_size;
  int tmp;

  for (tabl_size = 1; tabl_size < size; tabl_size++)
    {
      for (n = tabl_size; n; n = k)
        {
	  k = (n - 1) / 2;
	  if (tabl[n] > tabl[k])
	    heap_sort_swap(tabl, n, k);
	  else
	    break ;
        }
    }
  do_heap_sort(tabl, n, k, tabl_size);
}
