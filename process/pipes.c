#include <stdlib.h>
#include <unistd.h>

/*
 * Does "cat /etc/passwd | grep root | cut -d: -f1- | sed s/root/itworks/"
 */

void pipeline(char **cmd, int input)
{
  int pipefd[2] = { -1, -1 };
  pid_t pid;

  // make a pipe if needed
  if (*(cmd + 1))
    pipe(pipefd);
  pid = fork();
  // child
  if (pid == 0) {
    // if not first
    // takes input (pipefd[0]) as stdin
    if (input != -1) {
      dup2(input, STDIN_FILENO);
      close(input);
    }
    // if not last
    // puts stdout to pipefd[1]
    if (pipefd[1] != -1) {
      dup2(pipefd[1], STDOUT_FILENO);
      close(pipefd[1]);
    }
    // if not first
    if (pipefd[0] != -1)
      close(pipefd[0]);
    // executes
    system(*cmd);
    exit(1);
  }
  // parent
  else {
    // if not first
    if (input != -1)
      close(input);
    // if not last
    if (pipefd[1] != -1)
      close(pipefd[1]);
    // if not last
    if (*(cmd + 1))
      pipeline(cmd + 1, pipefd[0]);
  }
}

int main(int argc, char **argv)
{
  char *args[] = {"cat /etc/passwd", "grep root", "cut -d: -f1-", "sed s/root/itworks/", NULL};

  pipeline(args, -1);
  return (0);
}
