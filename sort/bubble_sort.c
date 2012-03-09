/* bubble_sort_char */

void bubble_sort_char_swap(char *str, int n1, int n2)
{
  char tmp;

  tmp = str[n1];
  str[n1] = str[n2];
  str[n2] = tmp;
}

void bubble_sort_char(char *str)
{
  int n1;
  int n2;

  for (n1 = 0; str[n1]; n1++)
    for (n2 = n1; n2 > 0 && str[n2] < str[n2 - 1]; n2--)
      bubble_sort_char_swap(str, n2, n2 - 1);
}

/* bubble_sort_char_char */

void bubble_sort_char_char_swap(char **tabl, int n1, int n2)
{
  char *tmp;

  tmp = tabl[n1];
  tabl[n1] = tabl[n2];
  tabl[n2] = tmp;
}

void bubble_sort_char_char(char **tabl)
{
  int n1;
  int n2;

  for (n1 = 0; tabl[n1]; n1++)
    for (n2 = n1; n2 > 0 && strcmp(tabl[n2], tabl[n2 - 1]) < 0; n2--)
      bubble_sort_char_char_swap(tabl, n2, n2 - 1);
}

/* bubble_sort_int */

void bubble_sort_int_swap(int *tabl, int n1, int n2)
{
  int tmp;

  tmp = tabl[n1];
  tabl[n1] = tabl[n2];
  tabl[n2] = tmp;
}

void bubble_sort_int(int *tabl)
{
  int n1;
  int n2;

  for (n1 = 0; tabl[n1]; n1++)
    for (n2 = n1; n2 > 0 && tabl[n2] < tabl[n2 -1]; n2--)
      bubble_sort_int_swap(tabl, n2, n2 - 1);
}
