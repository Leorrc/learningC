#include <stdio.h>

int main(void){

  unsigned int i = 0;

imprimir: //label
  printf("O valor de i eh: %u\n", i);
  i++;
  if (i < 3)
    goto imprimir;




  /*
  printf("O valor de i eh: %u\n", i);
  i++;
  printf("O valor de i eh: %u\n", i);
  i++;
  */
  return 0;
}
