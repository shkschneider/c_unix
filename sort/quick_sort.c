void quick_sort_swap(int *from, int *to)
{
  int tmp;

  tmp = *from;
  *from = *to;
  *to = tmp;
}

void quick_sort(int *tabl, int size)
{
  int *end = NULL;
  int *left = NULL;
  int *right = NULL;
  int *p = NULL;

  end = tabl + size - 1;
  if (tabl < end)
    {
      p = tabl;
      left = tabl;
      right = end;
      while (left < right)
	  {
            while (left < right && *right > *p)
	      right--;
	    quick_sort_swap(left, right);
            p = right;
            while (left < right && *left <= *p)
	      left++;
	    quick_sort_swap(right, left);
            p = left;
	  }
      quick_sort(tabl, left - tabl);
      quick_sort(left + 1, end - left);
    }
}
