#include <stdio.h>
#include "printf.h"

int main()

{
	//char	*n;
	//static char *s_hidden = "hi low\0don't print me lol\0";
    printf(" <%d>\n", ft_printf("this %2x nmber", 17));
    printf(" <%d>\n", printf("this %20d number", 17));
	printf("%s\n", ft_itoa_base(17, 16));
	return (0);
}
	
