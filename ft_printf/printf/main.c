#include <stdio.h>
#include <stdlib.h>
#include "printf.h"

int main()
{
  printf("\n<%d>\n", ft_printf("%1$"));
  printf("\n<%d>\n", printf("%1$"));
  return 0;
}
