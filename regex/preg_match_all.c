#include <sys/types.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>

char **preg_match_all(char *regex, char *str_request, int *nb_match)
{
  int i;
  regex_t preg;
  char **matches = NULL;
  regmatch_t *pmatch = NULL;
  char *str_regex = NULL;

  str_regex = malloc(sizeof(char) * (strlen(regex) + 2));
  strcpy(str_regex, regex);
  strcat(str_regex, "()");
  matches =  NULL;
  i = 0;
  if (!regcomp(&preg, str_regex, REG_EXTENDED))
    if (preg.re_nsub)
      {
        pmatch = malloc(sizeof(*pmatch) * preg.re_nsub);
        if (!regexec(&preg, str_request, preg.re_nsub, pmatch, 0))
          {
            matches = malloc(sizeof(char *) * preg.re_nsub);
            for (i = 1; i < (int)preg.re_nsub; i++)
              {
                matches[i - 1] = malloc(sizeof(char) * ((pmatch[i].rm_eo - pmatch[i].rm_so) + 1));
                strncpy(matches[i - 1], &str_request[pmatch[i].rm_so], (pmatch[i].rm_eo - pmatch[i].rm_so));
                matches[i - 1][(pmatch[i].rm_eo - pmatch[i].rm_so)] = '\0';
              }
            if (nb_match)
              *nb_match = i - 1;
            matches[i - 1] = NULL;
          }
        regfree(&preg);
      }
  free(str_regex);
  return (matches);
}
