#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int usrinfo(int uid)
{
  struct passwd *user_info = NULL;

  user_info = getpwuid(uid);
  if (user_info)
    {
      printf("pw_name: %s\n", user_info->pw_name);
      printf("pw_passwd: %s\n", user_info->pw_passwd);
      printf("pw_uid: %d\n", user_info->pw_uid);
      printf("pw_gid: %d\n", user_info->pw_gid);
      printf("pw_gecos: %s\n", user_info->pw_gecos);
      printf("pw_dir: %s\n", user_info->pw_dir);
      printf("pw_shell: %s\n", user_info->pw_shell);
      /* do NOT free */
      return (1);
    }
  return (0);
}
