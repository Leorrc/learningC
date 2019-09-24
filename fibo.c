#include <stdio.h>

int fibo(int);

int fibo(int n){
	int a = 0, b = 1, fibo = 0; n;

	while(fibo < n){
		fibo = a + b;
		a = b;
		b = fibo;
		printf("%d\n", fibo);
		
	}
}





