#include <stdio.h>

void ft_print_comb2(void){
  
  int i, j, k, l;

  for(i='0'; i<='9'; i++){
    for(j='0'; j<='9'; j++){
      for(k=i; k<='9'; k++){
        for(l=j+1; l<='9'; l++){
          printf("%c%c %c%c", i, j, k, l);

          if (i != '9' || j != '8' || k != '9' || l != '9'){
            printf(", ");
          }
        }
      }
    }
  }  
}


int main(void){

  ft_print_comb2();

  return 0;
}
