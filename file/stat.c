#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <stdlib.h>

char *array_chmod[] = { "---", "--x", "-w-", "-wx", "r--", "r-x", "rw-", "rwx" };

void my_stat(char *name, struct stat *st)
{
  int i;
  struct passwd	*passent = NULL;

  printf("%s:\n", name);
  printf(" Last access : %s", ctime(&(st->st_atime)));
  printf(" Last modification : %s", ctime(&(st->st_mtime)));
  printf(" Last status change : %s", ctime(&(st->st_ctime)));
  printf(" Current file size : %ld \n", st->st_size);
  printf(" Directory entry is on device %d\n", st->st_dev);
  printf(" Inode number is %lu\n", st->st_ino);
  passent = getpwuid(st->st_uid);
  if (passent)
    printf(" The owner of the file is #%d: %s\n", st->st_uid, passent->pw_name);
  else
    printf(" The owner of the file is #%d: (unknown)\n", st->st_uid);
  printf(" Access mode 0%o: ", st->st_mode);
  for (i = 6; i >= 0; i -= 3)
    printf("%s", array_chmod[(st->st_mode >> i) & 7]);
  printf("\n");
}

int main(int argc, char **argv)
{
  struct stat st;
  int i;

  i = (argc == 1 ? 0 : 1);
  while (i < argc)
    {
      if (stat(argv[i], &st) == 0)
	my_stat(argv[i], &st);
      else
	printf("Failed to stat %s.\n", argv[i]);
      i++;
    }
  return (0);
}
