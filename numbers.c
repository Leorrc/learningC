#include <stdio.h>

void ft_print_numbers(void){

  char num;

  for(num='0'; num<='9'; num++){
    putchar(num);
  }
}

int main(void){

  ft_print_numbers();

  return 0;
}
