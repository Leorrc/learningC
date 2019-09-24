#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Neste código será usado a fórmula de Heron que calcula a área
de um triângulo em função dos seus lados.
*/

//Calculo da área do triângulo
float areat(float a, float b, float c){

	float p, area;

	p = (a + b + c)/2; //p = semiperimetro
        area = sqrt(p*(p - a)*(p - b)*(p - c));
	return area;
}

//Avalia se os lados digitados formam um triângulo
bool condicao_triangulo(float a, float b, float c){

	if (a > abs(b - c) && a < (b + c)){
		return true;
	} else if (b > abs(a - c) && b < (a + c)){
		return true;
	} else if (c > abs(a - b) && c < (a + b)){
		return true;
	} else{
		return false;
	}
}


int main(void){
	
	float a, b, c, area;

	printf("Bem vindo(a) à Calculadora de Área de Triângulo!\n");
	
	
	printf("Digite o lado a = ");
	scanf("%f", &a);
	printf("Digite o lado b = ");
        scanf("%f", &b);
	printf("Digite o lado c = ");
        scanf("%f", &c);

	area = areat(a, b, c);
 
	if (condicao_triangulo(a, b, c)){
		printf("A área do triângulo é = %.2f\n", area);
	} else {
		printf("Os lados digitados não formam um triângulo!\n");
	}

	return 0;
}
