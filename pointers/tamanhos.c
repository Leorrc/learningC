#include <stdio.h>

void separador(void){
  
  int z;
  for (z=0; z<=20; z++)
    printf("=");
  printf("\n");
}

int main (void) {

  typedef struct {
    int dia, mes, ano;
  } data;
  printf ("sizeof (data) = %ld\n", sizeof (data));

  separador();
  
  int i = 1234;
  printf("i = %d\n", i);
  printf("&i = %ld\n", (long int) &i);
  printf("&i = %p\n", &i);
  
  separador();
  
  int j; int *p;
  j = 1234; p = &j;
  printf("*p = %d\n", *p); //p aponta para o valor de j
  printf("p = %ld\n", (long int) p); //endereço de p é o mesmo que &j
  printf("j = %ld\n", (long int) &j);
  printf("p = %p\n", (void *) p); //endereço de p em hexadecimal indicado pelo formato %p
  printf("&p = %p\n", (void *) &p);


  return 0;
}
