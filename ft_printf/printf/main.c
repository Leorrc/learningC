#include <stdio.h>
#include "printf.h"

int main()
{
	ft_printf("ft_printf (-) = |%15.20d|\n", -123456789);
       printf("---printf (-) = |%15.20d|\n", -123456789);
	ft_printf("ft_printf (+) = |%15.20d|\n", 123456789);
       printf("---printf (+) = |%15.20d|\n", 123456789);
/*	
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


	return (0);
}
