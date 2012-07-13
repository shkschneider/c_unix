/*
 * gcc shell.c -lreadline
 */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <strings.h>

/*
 * This program uses GNU libreadline
 * Configure with /etc/inputrc and/or ~/.inputrc
 */

int main(int argc, char **argv)
{
  char *cmd_line = NULL;
  char *s = NULL;

  using_history();
  while (42) {
    cmd_line = readline("$ ");
    // if ^D
    if (!cmd_line) {
      printf("\n");
      return (0);
    }
    // exit
    if (!strcasecmp(cmd_line, "exit"))
      return (0);
    if (strlen(cmd_line) > 0 && cmd_line[0] != ' ')
      add_history(cmd_line);
    // TODO add builtins with a list of function pointers
    system(cmd_line);
    // do not forget to free
    free(cmd_line);
  }

  return (0);
}
