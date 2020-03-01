#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

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

void  ft_putnbr(unsigned int i)
{
  if (i < 0)
  {
    ft_putchar('-');
    i = i * (-1);
  }
  if (i / 10 > 0)
    ft_putnbr(i / 10);
  ft_putchar((i % 10) + 48);
}

size_t  ft_strlen(const char *c)
{
  int i;

  i = 0;
  while (c[i])
    i++;
  return (i);
}

int     nblen(uintmax_t n, int base)
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
        ft_putstr("0x");
        ft_putstr(result);
        return (result);
}

int             ft_atoi(const char *str)
{
        long long       res;
        int                     sign;

        res = 0;
        sign = 1;
        while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' ||
                        *str == '\r' || *str == ' ')
                str++;
        if (*str == '-' || *str == '+')
        {
                if (*str == '-')
                        sign = sign * (-1);
                str++;
        }
        while (*str >= '0' && *str <= '9')
        {
                res = res * 10 + *str - 48;
                str++;
        }
        return (sign * res);
}

int             ft_str_is_numeric(char *str)
{
        int i;

        i = 0;
        while (str[i] != '\0')
        {
                if (str[i] < '0' || str[i] > '9')
                        return (0);
                i++;
        }
        return (1);
}
/*
char  *flags(const char *format, char *argument, char c)
{
  char *s;
  char *w;
  char *a;
  int i;
  int j;
  int len;

  i = 0;
  j = 0;
  s = (char *)format;
  a = argument;
  while (s[i] != c)
  {
    if (s[i] >= '0' && s[i] <= '9')
    {
      w[j] = s[i];
      j++;
    }
    i++;
  }
  len = ft_atoi((const char *)w);
  
}*/

size_t length(char *str, char c)
{
  size_t len;
  len = 0;
  while (str[len] != c && str[len])
    len++;
  return (len);
}

void    *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
        unsigned char           *d;
        const unsigned char     *s;

        d = dest;
        s = src;
        while (n != 0 && *s != (unsigned char)c)
        {
                *d++ = *s++;
                n--;
        }
        if (*s == (unsigned char)c)
        {
                *d = *s;
                return (++d);
        }
        return (NULL);
}

int     ft_printf(const char *format, ...)
{
  va_list   arg;
  int i;
  char *str;

  i = 0;
  va_start(arg, format);
  while (format[i])
  {
    if (format[i] != '%')
      ft_putchar(format[i]);
    else
    {
      i++;
      if (format[i] == 'c')
        ft_putchar(va_arg(arg, int));
      else if (format[i] == 'd')
        ft_putnbr(va_arg(arg, int));
      else if (format[i] == 's')
        ft_putstr(va_arg(arg, char *));
      else if (format[i] == 'p')
        ft_itoa_base(va_arg(arg, int), 16);
    }
    i++;
  }
  va_end(arg);
  return (ft_strlen(format));
}

int main()
{
  /*
  ft_printf("x = %c", 'a');
  ft_putchar('\n');
  ft_printf("x = %s", "abc");
  ft_putchar('\n');
  ft_printf("x = %d", 5);*/
  ft_printf("d = %s, c = %s, s = %s", "abc", "fbjigb" , "55586");
  ft_putchar('\n');
  
  return (0);
}
