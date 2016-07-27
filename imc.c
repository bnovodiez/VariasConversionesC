#include<stdio.h>

int main() {
	float altura;
	float peso;
	float resultadoimc;
	printf("Escribir la altura\n");
	scanf("%f",&altura);
	printf("Escribir tu peso\n");
	scanf("%f",&peso);

	resultadoimc = peso/(altura*altura);
	printf("Tu IMC es %f\n",resultadoimc);
	if (resultadoimc<18.5) {
		printf("Delgadez\n");
	} else {
		if (resultadoimc<25) {
			printf("Peso normal\n");
		} else {
			if (resultadoimc<30) {
				printf("Sobrepeso\n");
			} else {
				printf("Obeso\n");
			}
		}
	}
	return 0;
}

