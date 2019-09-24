#include <stdio.h>


void ft_print_alphabet(void){

  char abc;

  for(abc='a'; abc<='z'; abc++){

   putchar(abc);
  }
}

int main(void){
  ft_print_alphabet();

  return 0;

}
