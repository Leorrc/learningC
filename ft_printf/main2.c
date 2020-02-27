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

int   isnumber(char c)
{
  int   n;
  if (c >= '0' && c <= '9')
    n = 1;
  else
    n = 0;
  return (n);
}

char  field_flags(const char *format)
{
  char  flag;
  char  *f;
  int   i;

  f = (char *)format;
  i = 0;
  flag = 0;
  while (f[i])
  {
   if (f[i] == '-' || f[i] == '0')
   {
	   flag = f[i];
	   break ;
   }
   i++;
  }
  return (flag);
}

int   field_width(const char *format)
{
  int   width;
  char	*f;
  
  width = 0;
  f = (char *)format;
  while (*f)
  {
    if (isnumber(*f) && *f != '0')
    {
      while (isnumber(*f))
      {
        width = width * 10 + *f - 48;
        f++;
      }
	  break ;
    }
    f++;
  }
  return (width);
}

int   field_precision(const char *format)
{
  int   precision;

  precision = 0;
  while (*format)
  {
    if (*format == '.')
    {
      format++;
      while (isnumber(*format))
      {
        precision = precision * 10 + *format - 48;
        format++;
      }
	  break ;
    }
    format++;
  }
  return (precision);
}

char   field_conversions(const char *format)
{
  char  *conv;
  char  type;
  int   i;

  conv = "cspdiuxX%";
  type = 0;
  i = 0;
  format++;
  while (*conv)
  {
	if (strchr(format, *conv))
	{
      type = *conv;
      break ;
    }
    conv++;
  }
  return (type);
}

int   ft_printf(const char *format, ...)
{
  va_list   arg;
  char      *s;
  int       i;
  int       j;
  int       len;
  int       len2;

  va_start(arg, format);
  s = va_arg(arg, char *);
  i = 0;
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

