#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void troca (int *p, int *q) 
{
  int temp;
  temp = *p; *p = *q; *q = temp;
}

int main (void) {
  int *p, *q;
  int i, j;
  i = 5;
  j = 10;
  p = &i; q = &j;
  troca (p, q);
  printf("i = %d\n", i);
  printf("j = %d\n", j);

  return 0;
}

