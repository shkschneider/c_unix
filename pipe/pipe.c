#include <stdio.h>
#include <unistd.h>

/*
 * Does "cat /etc/passwd | grep root"
 */

int main(int argc, char **argv)
{
  int pipefd[2];
  pid_t pid;

  // make a pipe
  pipe(pipefd);
  pid = fork();
  // child
  if (pid == 0) {
    // takes stdin from pipefd[0]
    dup2(pipefd[0], STDIN_FILENO);
    // close unused hald of pipe
    close(pipefd[1]);
    // executes
    system("grep root");
  }
  // parent
  else {
    // puts stdout into pipefd[1]
    dup2(pipefd[1], STDOUT_FILENO);
    // close unused half of pipe
    close(pipefd[0]);
    // executes
    system("cat /etc/passwd");
  }
  return (0);
}
