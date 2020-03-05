#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_fields
{
  char      flag;
  char      type;
  int       width;
  int       precision;
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

char    *ft_strchr(const char *str, int ch)
{
        while (*str && *str != (char)ch)
                str++;
        if (*str == (char)ch)
                return ((char *)str);
        return (NULL);
}

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

char	*ft_strnew(int len)
{
	char	*new;

	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_memset(new, '\0', (len + 1));
	return (new);
}

void    *ft_memchr(const void *s, int c, size_t n)
{
        const char      *str;

        str = (const char *)s;
        while (n > 0)
        {
                if (*str == c)
                        return ((void *)(str++));
                str++;
                n--;
        }
        return (NULL);
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
   if (f[0] == '-' || f[0] == '0')
   {
	   flag = f[0];
	   break ;
   }
   i++;
  }
  return (flag);
}

int    field_width(const char *format, va_list arg)
{
  int   width;
  
  width = 0;
  while (*format)
  {
    if (*format == '*')
    {
        width = va_arg(arg, int);
        break ;
    }    
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

int    field_precision(const char *format, va_list arg)
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
      if (*format == '*')
      {
          precision = va_arg(arg, int);
          break ;
      }
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

t_fields    *field_value(const char *format, va_list arg)
{
    t_fields    *f;
    
    if (!(f = (t_fields *)malloc(sizeof(t_fields *))))
        return (NULL);
    f->flag = field_flags(format);
    f->width = field_width(format, arg);
    f->precision = field_precision(format, arg);
    f->type = field_types(format);
    return (f);
}

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

int   type_s(t_fields *f, char *arg)
{
    int     len;
    char    *s;
    
    len = ft_strlen(arg);
    s = ft_strdup(arg);
    if (f->precision)
    {
        if (f->precision == 0)
            ft_putchar('\0');
        else if (len > f->precision)
            s = ft_substr(arg, 0, f->precision);
    }
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
    else if (f->flag == '0')
        return (-1);
    else
    {
        while (f->width > 0)
        {
            ft_putchar(' ');
            f->width--;
        }
        ft_putstr(s);
    }
    return (0);
}

char    *precision_d_positive(t_fields *f, int arg)
{
    char    *p;
    char    *s;
    int     len;
    int     i;
    
    i = -1;
    s = ft_itoa_base(arg, 10);
    len = (int)ft_strlen(s);
    if (f->precision == 0 && arg == 0)
      p = "\0";
    else if (f->precision < len)
      p = s;
    else if (f->precision > len)
    {
      p = (char *)malloc(f->precision + 1);
      while (++i < (f->precision - len))
        p[i] = '0';
      while (i < f->precision)
      {
        p[i] = *s++;
        i++;
      }
      p[i] = '\0';
    }
  return (p);
}

char    *precision_d_negative(t_fields *f, int arg)
{
    char    *p;
    char    *s;
    int     len;
    int     i;
    
    i = 0;
    s = ft_itoa_base(arg, 10);
    len = ft_strlen(s) - 1;
    if (f->precision == 0 && arg == 0)
      p ="\0";
    else if (f->precision < len)
      p = s;
    else if (f->precision > len)
    {
      p = (char *)malloc(f->precision + 1);
      p[i] = '-';
      while (++i <= (f->precision - len))
        p[i] = '0';
      while (i <= f->precision)
      {
        s++;
        p[i] = *s;
        i++;
      }
      p[i] = '\0';
    }
    return (p);
}

char	*width_d(t_fields *f, char *d) 
{
	char	*w;
	int 	len;
	
	
	len = (int)ft_strlen(d);
	if (f->width <= len)
		w = ft_strdup(d);
	else
	{
		w = (char *)malloc(len + 1);
		f->width = f->width - len;
		while (f->width-- > 0)
			*w++ = ' ';
		while (*d)
			*w++ = *d++;		
	}
	return (w);
}

int		type_d(t_fields *f, int arg)
{
	char    *d;
	char		*w;
	
	d = 0;
	w = 0;
	if (arg > 0)
	    d = precision_d_positive(f, arg);
	else
	    d = precision_d_negative(f, arg);
	w = width_d(f, d);
	if (d)
	    ft_putstr(w);
	else
	    ft_putstr(ft_itoa_base(arg, 10));
	return (0);
}	

int		type_x(t_fields *f, int arg)
{
	char	*nbr;
	char	*x;
	long	i;
	int		len;
	
	i = arg;
	nbr = ft_itoa_base(i, 16);
	len = (int)ft_strlen(nbr);
	if (f->precision)
	{
		if (f->precision == 0)
			ft_putchar('\0');
		else if (len > f->precision)
			x = ft_substr(nbr, 0, f->precision);
	}
	len = ft_strlen(x);
	if (f->width <= len)
	{
		ft_putstr(x);
		return (0);
	}
	f->width = f->width - len;
	if (f->flag == '-')
	{
		ft_putstr(x);
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
		ft_putstr(x);
	}
	else
	{
		while (f->width > 0)
		{
			ft_putchar(' ');
			f->width--;
		}
		ft_putstr(x);
	}
	return (0);
}

int   ft_printf(const char *format, ...)
{
	va_list     arg;
	t_fields    *f;
	
	va_start(arg, format);

	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format);
		else
		{
            f = field_value(format, arg);
		    if (f->type == 's')
                type_s(f, va_arg(arg, char *));
            else if (f->type == 'c')
                type_c(f, va_arg(arg, int));
			else if (f->type == 'd' || f->type == 'i')
				type_d(f, va_arg(arg, int));
			else if (f->type == 'x')
				type_x(f, va_arg(arg, int));
            while (*format != f->type)
                format++;
		}
		format++;
    }
	va_end(arg);
	return (ft_strlen(format));
}

int main()
{
    ft_printf("ft_printf = |%.10d|\n", -123456);
       printf("---printf = |%.10d|\n", -123456);
	//printf("%s\n", ft_itoa_base(200, 10));
	return 0;
}
