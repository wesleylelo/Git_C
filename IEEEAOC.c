#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "BIBLIOIEEE745.h"


int main(int argc, char *argv[]) {


int numero_inteiro;
double entrada;
int exp = 0;
int precisao;
int get = 0;
int* expoente;
int* parte_inteira;
int* parte_fracionada;
int* vmantissa;

do{
	printf("DIGITE A PRECISAO DO PONTO FLUTUANTE\n");
	scanf("%d", &precisao);
}while(precisao != 32 && precisao != 64 && precisao != 8);

printf("DIGITE UM NUMERO\n");
scanf("%lf", &entrada);

numero_inteiro = (int)entrada;
entrada = (entrada - (int)entrada);

printf("%lf\n", entrada);

if(precisao == 8){
	
	
}
else if(precisao == 32){
	parte_inteira = decimaltobinario(numero_inteiro, 24, &exp);
	expoente = decimaltobinario(127 + exp, 9, NULL);
	int j;
	printf("Parte Inteira:\n");
	for(j = 0; j < 24; j++){
		if(parte_inteira[j]!=2)
			printf("%d", parte_inteira[j]);
	}
	printf("\n");
	printf("\n");
	printf("Parte Expoente:\n");
	for(j = 0; j < 9; j++)
		printf("%d", expoente[j]);
	printf("\n");
	printf("\n");
	parte_fracionada = fracionariotobinario(entrada,23 - exp + 1, &get);
	printf("Parte Fracionada: \n");
	
	for(j = 0; j < 23- exp +1; j++)
		printf("%d", parte_fracionada[j]);
	printf("\n");
	printf("\n");
	vmantissa = mantissa(parte_inteira, parte_fracionada,23);
	printf("Parte Mantissa:\n");
	for(j = 0; j < 24; j++)
		printf("%d", vmantissa[j]);
	printf("\n");
	printf("\n");
} else {
	
}


printf("%d", exp);
return 0;
}



