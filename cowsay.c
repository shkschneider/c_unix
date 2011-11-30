#include <stdio.h>

int main(int argc, char **argv)
{
  int i;

  if (argc == 1)
    printf("< moOh >\n");
  for (i = 1; i < argc; i++)
    if (i == 1)
      printf("/ %s \\\n", argv[i]);
    else if (i == argc - 1)
      printf("\\ %s /\n", argv[i]);
    else
      printf("| %s |\n", argv[i]);
  printf("  \\ ^__^\n");
  printf("    (oo)\\_______\n");
  printf("    (__)\\       )\\/\\\n");
  printf("        ||----w |\n");
  printf("        ||     ||\n");
  return (0);
}
