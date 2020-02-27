#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

void  ft_putstr(char *s)
{
  while(*s)
  {
    write(1, s, 1);
    s++;
  }
}


int   ft_printf(const char *format, ...)
{
  va_list   arg;
  char      *fields;
  char      *s;
  int       i;
  int       j;
  int       len;
  int       len2;

  va_start(arg, format);
  s = va_arg(arg, char *);
  /*
  fields = (char *)malloc(10);
  //%[flags][width][.precision][size]type
  while (format[i])
  {
    if (format[i] != '%')
      write(1, &format[i], 1);
    else
    {
      i++;
      while (format[i] == '-')
        fields[0] = '-';
      while (format[i] >= '0' && format[i] <= '9')
        fields[1] = format[i];
      while (format[i] == 's')
        fields[3] = '-';
    }
    i++;
  }
  len = 10;
  i = 0;
  while (i < len)
  {
    while (s)
      write(1, &s[i], 1);
    write(1, " ", 1);
    i++;
  }
  */
  while (format[i])
  {
    if (format[i] != '%')
      write(1, &format[i], 1);
    else
    {
      i++;
      if (format[i] == '5' && format[i + 1] == 's')
      {
        len = atoi(&format[i]);
        len2 = strlen(s);
        j = 0;
        while (j < (len - len2))
        {
          write(1, " ", 1);
          j++;
        }
        ft_putstr(s);
        i++;
      }
    }
    i++;
  }
  va_end(arg);
  return (strlen(format));
}

int main()
{
  char *p = "abc";
  ft_printf("|%5s|\n", p);
  return 0;
}

