#include <stdio.h>
#include <stdlib.h>
#include "printf.h"

int main()
{
  ft_printf("%*s\n", 13, "leonardo");
  /*
  printf("\n<%d>\n", ft_printf("%%-*.3s LYDI == |%-*.3s|n", 5, "LYDI"));
  printf("\n<%d>\n", printf("%%-*.3s LYDI == |%-*.3s|n", 5, "LYDI"));*/
  return 0;
}
