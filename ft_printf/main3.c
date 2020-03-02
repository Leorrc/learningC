#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void  ft_putstr(char *s)
{
  while(*s)
  {
    write(1, s, 1);
    s++;
  }
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

  conv = "cspdiuxX%";
  type = 0;
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
	va_list	arg;
	char	*s;
	size_t	len;	

	va_start(arg, format);
	s = va_arg(arg, char *);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format);
		else
		{
			format++;
			if (field_conversions(format) == 's')
			{
				if (field_flags(format) == '-')
				{
					len = field_width(format);
					if (len > ft_strlen(s))
					{
						len = len - ft_strlen(s);
						ft_putstr(s);
						while (len > 0)
						{	
							ft_putchar(' ');
							len--;
						}
					}
				}
			}
		}
		format++;
	}
	va_end(arg);
	return (strlen(format));
}

int main()
{
  char *p = "abc";
  ft_printf("|%-5s|\n", p);
  
  /*
  const char  *format;
  char f;

  format = "%5.6s";
  f = field_flags(format);
  printf("%c", f);
 */ 




  return 0;
}

