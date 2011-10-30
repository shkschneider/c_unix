#include <stdlib.h>
#include <string.h>
#include <regex.h>

char		*preg_match_once(char *regex, char *str_request)
{
  char		*match;
  regex_t	preg;
  regmatch_t	*pmatch;
  size_t	size;
  char          *str_regex;

  str_regex = malloc(sizeof(char) * (strlen(regex) + 2));
  strcpy(str_regex, regex);
  strcat(str_regex, "()");
  if (regcomp(&preg, str_regex, REG_EXTENDED) == 0)
    {
      pmatch = malloc(sizeof(regmatch_t) * preg.re_nsub);
      if (regexec(&preg, str_request, preg.re_nsub, pmatch, 0) == 0)
	{
	  size = pmatch[0].rm_eo - pmatch[0].rm_so;
	  match = malloc(sizeof(char) * (size + 1));
	  memset(match, '\0', size + 1);
	  strncpy(match, &str_request[pmatch[0].rm_so], size);
	}
      regfree(&preg);
      return (match);
    }
  return (NULL);
}
