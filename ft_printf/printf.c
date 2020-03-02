#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_fields
{
  char    flag;
  char    type;
  int width;
  int  precision;
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

<<<<<<< HEAD
void	ft_putnbr(int n)
{
	unsigned int	j;

	j = n;
	if (n < 0)
	{
		ft_putchar('-');
		j = j * 10;
	}
	if (j / 10 > 0)
		ft_putnbr(j / 10);
	ft_putchar((j % 10) + 48);
}

=======
>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
char    *ft_strchr(const char *str, int ch)
{
        while (*str && *str != (char)ch)
                str++;
        if (*str == (char)ch)
                return ((char *)str);
        return (NULL);
}

<<<<<<< HEAD
char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		len;

	len = 0;
	while (s[len])
		len++;
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (0);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

=======
>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
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

<<<<<<< HEAD
int     nblen(long n, int base)
{
        int             len;

        len = 1;
        if (n < 0)
        {
                n *= -1;
                len = 2;
        }
        while (n / base > 0)
        {
                n = n / base;
                len++;
        }
        return (len);
}

char    *ft_itoa_base(long i, int base)
{
        char    *result;
        char    *tab_base;
        long    len;
        long    p;

        p = nblen(i, base);
        len = p;
        tab_base = (char *)malloc(sizeof(char) * 17);
        tab_base = "0123456789abcdef";
        if (!(result = (char *)(malloc((len + 1) * sizeof(char)))))
                return (NULL);
        if (i == 0)
                result[0] = '0';
        if (i < 0)
        {
                result[0] = '-';
                i *= -1;
        }
        while (i / base >= 0 && ((i > 0) ? (--len >= 0) : (--len > 0)))
        {
                result[len] = tab_base[i % base];
                i = i / base;
        }
        result[p] = '\0';
        return (result);
}

=======
>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
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

<<<<<<< HEAD
int    field_width(const char *format, va_list arg)
=======
int    field_width(const char *format)
>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
{
  int   width;
  
  width = 0;
  while (*format)
  {
<<<<<<< HEAD
    if (*format == '*')
    {
        width = va_arg(arg, int);
        break ;
    }    
=======
>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
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

<<<<<<< HEAD
int    field_precision(const char *format, va_list arg)
=======
int    field_precision(const char *format)
>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
{
  int   precision;
  char  type;

  type = field_types(format);
  precision = 0;
  while (*format && *format != type)
  {
    if (!(ft_strchr(format, '.')))
    {
      precision = -1;
      break ;
    }
    else if (*format == '.')
    {
      format++;
<<<<<<< HEAD
      if (*format == '*')
      {
          precision = va_arg(arg, int);
          break ;
      }
=======
>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
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

<<<<<<< HEAD
t_fields    *field_value(const char *format, va_list arg)
=======
t_fields    *field_value(const char *format)
>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
{
    t_fields    *f;
    
    if (!(f = (t_fields *)malloc(sizeof(t_fields *))))
        return (NULL);
    f->flag = field_flags(format);
<<<<<<< HEAD
    f->width = field_width(format, arg);
    f->precision = field_precision(format, arg);
=======
    f->width = field_width(format);
    f->precision = field_precision(format);
>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
    f->type = field_types(format);
    return (f);
}

<<<<<<< HEAD
int    type_c(t_fields *f, int arg)
{
    unsigned char c;
    c = (unsigned char)arg;
    if (f->width == 0)
        ft_putchar((char)c);
    else if (f->flag == '-')
    {
        ft_putchar(c);
        while (f->width > 0)
        {
            ft_putchar(' ');
            f->width--;
        }
    }
    else
    {
        while (f->width > 0)
        {
            ft_putchar(' ');
            f->width--;
        }
        ft_putchar(c);
    }
    return (0);
}

=======
>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
int   type_s(t_fields *f, char *arg)
{
    int     len;
    char    *s;
    
    len = ft_strlen(arg);
<<<<<<< HEAD
=======
    s = (char *)malloc(len + 1);
>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
    if (f->precision)
    {
        if (f->precision == 0)
            ft_putchar('\0');
<<<<<<< HEAD
        else if (len > f->precision)
            s = ft_substr(arg, 0, f->precision);
    }
=======
        else if (len >= f->precision)
            s = ft_substr(arg, 0, f->precision);
    }


    //ft_putchar('1');
    //ft_putchar('\n');


>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
    len = ft_strlen(s);
    if (len >= f->width)
    {
        ft_putstr(s);
        return (0);
    }
    f->width = f->width - len;
    if (f->flag == '-')
    {
        ft_putstr(s);
        while (f->width > 0)
        {
            ft_putchar(' ');
            f->width--;
        }
    }
<<<<<<< HEAD
    else if (f->flag == '0')
        return (-1);
=======
>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
    else
    {
        while (f->width > 0)
        {
            ft_putchar(' ');
            f->width--;
        }
        ft_putstr(s);
    }
<<<<<<< HEAD
    return (0);
}

int		type_d(t_fields *f, int arg)
{
	char 	*nbr;
	char	*n;
	long	i;

	i = arg;
	nbr = ft_itoa_base(i, 10);
	if (f->precision)
	{
		if (f->precision == 0)
			ft_putchar('\0');
		else if ((int)ft_strlen(nbr) > f->precision)
			n = ft_substr(nbr, 0, f->precision);
	}
	if (f->width <= (int)ft_strlen(n))
	{
		ft_putstr(n);
		return (0);
	}
	f->width = f->width - ft_strlen(n);
	if (f->flag == '-')
	{
		ft_putstr(n);
		while (f->width > 0)
		{
			ft_putchar(' ');
			f->width--;
		}
	}
	else if (f->flag == '0')
	{
		while (f->width > 0)
		{
			ft_putchar('0');
			f->width--;
		}
		ft_putstr(n);
	}
	else
	{
		while (f->width > 0)
		{
			ft_putchar(' ');
			f->width--;
		}
		ft_putstr(n);
	}
	return (0);
}

=======
    free(s);
    return (0);
}

>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
int   ft_printf(const char *format, ...)
{
	va_list     arg;
	t_fields    *f;
	
	va_start(arg, format);
<<<<<<< HEAD

	while (*format)
	{
=======
	while (*format)
	{
	  f = field_value(format);
>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
		if (*format != '%')
			ft_putchar(*format);
		else
		{
<<<<<<< HEAD
            f = field_value(format, arg);
		    if (f->type == 's')
                type_s(f, va_arg(arg, char *));
            else if (f->type == 'c')
                type_c(f, va_arg(arg, int));
			else if (f->type == 'd' || f->type == 'i')
				type_d(f, va_arg(arg, int));
            while (*format != f->type)
                format++;
		}
		format++;
    }
=======
		    if (f->type == 's')
          type_s(f, va_arg(arg, char *));
        while (*format != f->type)
          format++;
		}
		format++;
  }
>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
	va_end(arg);
	return (ft_strlen(format));
}

int main()
{
<<<<<<< HEAD
    ft_printf("ft_printf = |%d|\n", -4);
    printf("printf = |%d|\n", -4);
	//printf("%s\n", ft_itoa_base(200, 10));
	return 0;
}



=======
  char *p = "abc";
  char *q = "leonardo";
  ft_printf("|%13s| |%13s|\n", p, q);
  return 0;
}
>>>>>>> effbd94031711372d3e902fa25d3407965ec0526
