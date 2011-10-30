void	quick_sort_swap_right(int *left, int *right)
{
  int	tmp;

  tmp = *left;
  *left = *right;
  *right = tmp;
}

void	quick_sort_swap_left(int *left, int *right)
{
  int	tmp;

  tmp = *right;
  *right = *left;
  *left = tmp;
}

void	quick_sort(int *tabl, int size)
{
  int	*end;
  int	*left;
  int	*right;
  int	*p;

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
	    quick_sort_swap_right(left, right);
            p = right;
            while (left < right && *left <= *p)
	      left++;
	    quick_sort_swap_left(left, right);
            p = left;
	  }
      quick_sort(tabl, left - tabl);
      quick_sort(left + 1, end - left);
    }
}
