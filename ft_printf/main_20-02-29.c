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

char    *ft_strchr(const char *str, int ch)
{
        while (*str && *str != (char)ch)
                str++;
        if (*str == (char)ch)
                return ((char *)str);
        return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	sub = (char *)malloc((len + 1) * (sizeof(char)));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < start && s[i])
		i++;
	j = 0;
	while (j < len && s[i])
	{
		sub[j] = s[i];
		j++;
		i++;
	}
	sub[j] = '\0';
	return (sub);
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

void    *ft_memset(void *str, int c, size_t len)
{
        size_t  i;
        char    *s;

        s = str;
        i = 0;
        while (i < len)
        {
                s[i] = c;
                i++;
        }
        return (s);
}

char   field_types(const char *format)
{
  char  *conv;
  char  type;

  conv = "cspdiuxX%";
  type = 0;
  format++;
  while (*conv)
  {
	if (ft_strchr(format, *conv))
	{
      type = *conv;
      break ;
    }
    conv++;
  }
  return (type);
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
  
  width = 0;
  while (*format)
  {
    if (isnumber(*format) && *format != '0')
    {
      while (isnumber(*format))
      {
        width = width * 10 + *format - 48;
        format++;
      }
      break ;
    }
    format++;
  }
  return (width);
}

size_t    field_precision(const char *format)
{
  int   precision;
  char  type;

  type = field_types(format);
  precision = 0;
  while (*format && *format != type)
  {
    if (ft_strchr(format, '.') == NULL)
    {
      precision = -1;
      break ;
    }
    else if (*format == '.')
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

t_fields    *field_value(const char *format)
{
    t_fields    *f;
    
    if (!(f = (t_fields *)malloc(sizeof(t_fields *))))
        return (-1);
    f->flag = field_flags(format);
    f->width = field_width(format);
    f->precision = field_precision(format);
    f->type = field_types(format);
    return (f);
}

t_fields    *flag_minus(char *s, n)
{
    t_fields *
}

int   type_s(const char *format, t_fields *f, char *arg)
{
    size_t  len;
    char    *str;        
    
    len = ft_strlen(arg);
    if (f->precision > -1)
    {
        if (f->precision == 0)
            ft_putchar('\0');
        else if (len > f->precision)
            s = ft_substr(arg, 0, f->precision);
    }
    if (t->flag = '-')
    {
        if (len >= f->width)
            ft_putstr(s);
        else
            
    }   
    return (0);
}

int   ft_printf(const char *format, ...)
{
	va_list     arg;
	t_fields    *f;
	
	va_start(arg, format);
	f = field_value(format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format);
		else
		{
		    if (f->type == 's')
                type_s(format, f, va_arg(arg, char *));
            while (*format != 's')
                format++;
		}
		format++;
    }
	va_end(arg);
	return (ft_strlen(format));
}

int main()
{
  char *p = "abc";
  char *q = "abc";
  ft_printf("|%5s|\n", p);
  printf("|%5s|\n", q);
  /*
  const char  *format;
  char f;

  format = "%5.6s";
  f = field_flags(format);
  printf("%c", f);
 */ 




  return 0;
}
