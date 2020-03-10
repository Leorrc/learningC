#include <stdio.h>
#include "printf.h"

int main()
{
	char *a;

	a = "\0";
	ft_printf("ft_printf (+) = |%-10%|\n");
       printf("---printf (+) = |%-10%|\n");
	return (0);
}
	
	
	
	
	
	
	
	
	
	
	
	/*
	ft_printf("ft_printf (-) = |%015.20d|\n", -123456789);
       printf("---printf (-) = |%015.20d|\n", -123456789);

	int a = 123456789;
	ft_printf("ft_printf (+) = |%10X|\n", a);
       printf("---printf (+) = |%10X|\n", a);
	
char *d;
	char *s;
	int		len;

	s = "-123456789";
	d = ft_strnew(15);
	len = ft_strlen(s);
	d[0] = '-';
	ft_memset(&d[1], '*', 15-len + 1);
	ft_memmove(&d[15 - len + 2], &s[1], len);
	printf("|%s|\n", d);
*/
