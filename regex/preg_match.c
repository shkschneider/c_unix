#include <regex.h>
#include <stdlib.h>

int		preg_match(char *str_regex, char *str_request)
{
  regex_t	preg;

  if (regcomp(&preg, str_regex, REG_NOSUB | REG_EXTENDED) == 0)
    {
      if (regexec(&preg, str_request, 0, NULL, 0) == 0)
	{
	  regfree(&preg);
	  return (1);
	}
      regfree(&preg);
    }
  return (0);
}
