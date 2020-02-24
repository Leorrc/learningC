#include <stdio.h>
#include <string.h>
#include <stdarg.h>

char  minus_flag(const char *format, char *arg)


int   ft_printf(const char *format, ...)
{
  va_list arg;
  int     i;

  va_start(arg, format);
  while (format[i])
  {
    if (format[i] != '%')
      printf("%c", format[i]);
    else
    {
      i++;
      

    }
  }
  va_end(arg);
  return (strlen(format));
}

int main()
{
  char *p = "abc";
  printf("|%-5s|\n", p);
  return 0;
}

