#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_fields
{
  char    flag;
  char    type;
  size_t  width;
  size_t  precision;
} t_fields;

void  ft_putchar(char c)
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

size_t    field_width(const char *format)
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

size_t    field_precision(const char *format)
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

int   type_s(const char *format, char *arg)
{
  size_t   len;
  t_fields *f;

  if (!(f = (t_fields *)malloc(sizeof(t_fields *))))
    return (-1);
  f->flag = field_flags(format);
  f->width = field_width(format);
  f->precision = field_precision(format);
  len = strlen(arg);
  if (f->flag == '-')
  {
    if (f->width > ft_strlen(arg))
    {
     f->width = f->width - len;
     ft_putstr(arg);
     while (f->width > 0)
     {
       ft_putchar(' ');
       f->width--;
     }
    }
    else
      ft_putstr(arg);
  }
  return (0);
}

int   ft_printf(const char *format, ...)
{
	va_list	arg;
	char	*s;

	va_start(arg, format);
	s = va_arg(arg, char *);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format);
		else
		{
			format++;
      type_s(format, s); 
			while (*format != 's')
        format++;
    }
		format++;
	}
	va_end(arg);
	return (strlen(format));
}

int main()
{
  char *p = "abc";
  char *q = "abc";
  ft_printf("|%-5s|\n", p);
  printf("|%-5s|\n", q);
  /*
  const char  *format;
  char f;

  format = "%5.6s";
  f = field_flags(format);
  printf("%c", f);
 */ 




  return 0;
}

