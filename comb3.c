#include <stdio.h>


void ft_print_combn(void){

  int i, j, k;

  for(i='0'; i<='9'; i++){
    for(j=i+1; j<='9'; j++){
      for(k=j+1; k<='9'; k++){
        printf("%c%c%c", i, j, k);

        if(k != '7' || i != '8' || j != '9'){
          printf(", ");
        }
      }
    }
  }
}

int main(void){

  ft_print_combn();

  return 0;

}



