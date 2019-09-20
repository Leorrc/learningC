#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int main(void) {

  //Definindo variáveis
  char c;
  bool b;
  int i;
  float f;
  double d;

  printf("\nTamanho (sizeof)\n");
  printf("c = %zu bytes / %zu bits\n", sizeof c, sizeof c * 8);
  printf("b = %zu bytes / %zu bits\n", sizeof b, sizeof b * 8);
  printf("i = %zu bytes / %zu bits\n", sizeof i, sizeof i * 8);
  printf("f = %zu bytes / %zu bits\n", sizeof f, sizeof f * 8);
  printf("d = %zu bytes / %zu bits\n", sizeof d, sizeof d * 8);

  printf("\nValor max que cabe em cada variável\n");
  char uc = 127;
  printf("max c = %c\n", uc);


  
return 0;
}
