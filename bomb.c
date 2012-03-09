#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
 * ============================================================
 * WARNING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * ============================================================
 * THIS CODE WILL HARM YOUR COMPUTER.
 * IT WILL CONSUME ALL COMPUTER POWER BUT WON'T MAKE IT REBOOT.
 * FOR TESTING PURPOSE ONLY.
 *
 * This was a failed attempt to achieve infinite pipes.
 * ============================================================
 */

void bomb(char **cmd, int input)
{
  int pfds[2] = { -1, -1 };
  pid_t pid;

  if (*(cmd + 1))
    pipe(pfds);
  if ((pid = fork()) == -1)
    return ;
  if (pid == 0) {
    if (input != -1) {
      dup2(input, STDIN_FILENO);
      close(input);
    }
    if (pfds[1] != -1) {
      dup2(pfds[1], STDOUT_FILENO);
      close(pfds[1]);
    }
    if (pfds[0] != -1)
      close(pfds[0]);
    system(*cmd);
    exit(1);
  }
  else {
    if (input != -1)
      close(input);
    if (pfds[1] != -1)
      close(pfds[1]);
    if (*cmd + 1) /* HERE IS THE PROBLEM: SHOULD BE *(cmd + 1) */
      run_pipeline(cmd + 1, pfds[0]);
  }
}

int main(int argc, char **argv)
{
  int i;
  char *args[] = {"echo YOUR COMPUTER WILL COMPLETELY FREEZE", NULL};

  bomb(args, -1);
  return (1); /* THIS CODE ALWAYS FAILS */
}
