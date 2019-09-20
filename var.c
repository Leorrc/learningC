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
  
  //Operador sizeof
  printf("\nTamanho (sizeof)\n");
  printf("c = %zu bytes / %zu bits\n", sizeof c, sizeof c * 8);
  printf("b = %zu bytes / %zu bits\n", sizeof b, sizeof b * 8);
  printf("i = %zu bytes / %zu bits\n", sizeof i, sizeof i * 8);
  printf("f = %zu bytes / %zu bits\n", sizeof f, sizeof f * 8);
  printf("d = %zu bytes / %zu bits\n", sizeof d, sizeof d * 8);

  //Limites que cabem em cada variável
  printf("\nValor max que cabe em cada variável. Ver lib limits.h\n");
  printf("\n");
  printf("Variável char\n");
  char maxc = SCHAR_MAX;
  char minc = SCHAR_MIN;
  unsigned char max_uc = UCHAR_MAX;
  unsigned char min_uc = 0;
  char valor_c = 255;
  printf("Definição do valor máximo de char\n");
  printf("tamanho de char = 8 bits\n");
  printf("Maior valor de 8 bits em binário = 11111111\n");
  /*bits_char=`bc << EOF
    ibase=2
    11111111
    EOF
    `
  printf("Maior valor de 8 bits em decimal = %d\n", bits_char);
  */
  printf("max signed char = %d / min signed char = %d\n", maxc, minc);
  printf("max unsigned char = %d / min unsigned char = %d\n", max_uc, min_uc);
  printf("Colocando o valor máximo (255) numa signed char c = %d\n", valor_c);
  
return 0;
}
