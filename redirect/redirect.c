#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/*
 * Does "grep root < /etc/passwd > out"
 */

int main(int argc, char **argv)
{
  int in, out;
  char *grep_args[] = {"grep", "root", NULL};

  // open input and output files
  in = open("/etc/passwd", O_RDONLY);
  out = open("out", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
  // replace standard input with input file
  dup2(in, STDIN_FILENO);
  // replace standard output with output file
  dup2(out, STDOUT_FILENO);
  // close unused file descriptors
  close(in);
  close(out);
  // execute grep
  execvp("grep", grep_args);
  return (0);
}
