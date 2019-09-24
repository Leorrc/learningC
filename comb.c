#include <stdio.h>

void ft_print_comb(void){
  
  int i, j, k;

  for(i='0'; i<='9'; i++){
    for(j=i+1; j<='9'; j++){
      for(k=j+1; k<='9'; k++){
        printf("%c%c%c", i, j, k);
        //putchar(i);
        //putchar(j);
        //putchar(k);

        if (i != '7' || j != '8' || k != '9'){
          printf(", ");
          //putchar(',');
          //putchar(' ');
        }
      }
    }
  }  
}


int main(void){

  ft_print_comb();

  return 0;
}
