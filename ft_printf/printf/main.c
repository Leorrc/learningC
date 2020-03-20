#include <stdio.h>
#include "printf.h"

int main()
{
  int a;

  a = ft_printf("%");
  printf("\n%d\n", a);
  a = printf("%");
  printf("\n%d\n", a);
  return (0);
}
