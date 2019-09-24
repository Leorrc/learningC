#include <stdio.h>


void ft_print_reverse_alphabet(void){

  char abc;

  for(abc='z'; abc>='a'; abc--){
    putchar(abc);
  }
}
int main(void){

  ft_print_reverse_alphabet();



  return 0;
}
