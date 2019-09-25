#include <stdio.h>
#include <stdint.h>
#include <limits.h>


void ft_putnbr(int nb){

  printf("%i\n", nb);

}
int main (void){

  /*
  int i = INT_MAX;
  unsigned ui = UINT_MAX;

  printf("i = %i\n", i);
  printf("ui = %u\n", ui);
  */

  ft_putnbr(2147483647);
  return 0;
}
