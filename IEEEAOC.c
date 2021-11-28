#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "BIBLIOIEEE745.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
setlocale(LC_ALL, "Portuguese");

int numero_inteiro;
double entrada;
int exp = 0;
int precisao;
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


if(precisao == 8){
	
	
}
else if(precisao == 32){
	
	parte_inteira = decimaltobinario(numero_inteiro, 23, &exp);
	parte_fracionada = fracionariotobinario(entrada,23);
	vmantissa = mantissa(parte_inteira, parte_fracionada,23);
} else {
	
}
int j;
for(j = 0; j < 23; j++)
		printf("Parte Inteira %d\n", parte_inteira[j]);
printf("\n");
for(j = 0; j < 23; j++)
		printf("Parte Fracionada %d\n", parte_fracionada[j]);
printf("\n");
for(j = 0; j < 23; j++)
		printf("Parte Mantissa %d\n", vmantissa[j]);
printf("%d", sizeof(parte_fracionada)/sizeof(parte_fracionada[0]));
printf("%d", exp);
return 0;
}



