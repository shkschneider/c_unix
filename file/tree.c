#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <stdlib.h>
#include <string.h>

void		do_a_directory(char *pathname, int level)
{
  DIR		*directory;
  struct dirent	*entry;
  char		*newname;
  struct stat	statbuf;
  long		where;
  int		retval;
  int		i;

  /* └ ├ ─ */
  for (i = 0; i < level; i++)
    printf("  ");
  printf("%s\n", pathname);
  if (!(directory = opendir(pathname)))
    {
      fprintf(stderr, "Cannot open %s\n", pathname);
      return ;
    }
  while ((entry = readdir(directory)))
    {
      if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
	continue ;
      newname = malloc(sizeof(char) * MAXPATHLEN);
      strcpy(newname, pathname);
      strcat(newname, "/");
      strcat(newname, entry->d_name);
      if (!stat(newname, &statbuf) && (statbuf.st_mode & S_IFDIR))
	{
	  where = telldir(directory);
	  closedir(directory);
	  do_a_directory(newname, level + 1);
	  if(!(directory = opendir(pathname)))
	    {
	      fprintf(stderr, "Cannot open %s\n", pathname);
	      return ;
	    }
          seekdir(directory, where);
	}
      free(newname);
    }
  closedir(directory);
}

int	main(int argc, char **argv)
{
  int	i;

  if (argc < 2)
    {
      fprintf(stderr, "Usage: dtree directory\n");
      return (1);
    }
  for (i = 1; i < argc; i++)
    do_a_directory(argv[i], 0);
  return (0);
}
