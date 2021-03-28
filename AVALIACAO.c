#include <stdio.h>
#include <string.h>
#include "BIBLIO_ORDERACAO.h"
void bubblesort2(char *v, int n){
	char aux;
	int i, j, trocou = 1;
	for (i = 0; i < n - 1; i++){
		trocou = 0;
		for(j = 0; j < n- 1; j++){
			if (v[j] > v[j+1]){
				trocou = 1;
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
}


int main(){
	char a, b, c;
	FILE *arquivos[6];
	arquivos[0] = fopen("arquivo1.txt", "w+");
	arquivos[1] = fopen("arquivo2.txt", "w+");
	arquivos[2] = fopen("arquivo3.txt", "w+");
	arquivos[3] = fopen("arquivo4.txt", "w+");
	arquivos[4] = fopen("arquivo5.txt", "w+");
	arquivos[5] = fopen("arquivo6.txt", "w+");
	char vect[3], collection[] = {"asdqwuieprmanchrbslokjnrews"};
	int i = 0, j = 0, cont = 0, d = 1, e = 0, f = 0;
	for (i =0; i <= 27; i++){
		if(j == 3) {
			bubblesort2(&vect, 3);
			printf("%s\n", vect);
			if(cont == 0){
				fputs(vect, arquivos[0]);
				cont++;
				vect[0] = '\0';
			} else if(cont == 1){
				fputs(vect, arquivos[1]);
				cont++;
				vect[0] = '\0';
			} else{
				fputs(vect, arquivos[2]);
				cont = 0;
				vect[0] = '\0';
			}
			j = 0;
		}
		
		vect[j] = collection[i];
		/*
		if (j < 3 && i == 26){
			bubblesort2(&vect, 3);
			printf("Aqui %s\n", vect);
			if(cont == 0){
				fputs(vect, arquivos[0]);
				cont++;
				vect[0] = '\0';
			} else if(cont == 1){
				fputs(vect, arquivos[1]);
				cont++;
				vect[0] = '\0';
			} else{
				fputs(vect, arquivos[2]);
				cont = 0;
				vect[0] = '\0';
			}*/
		j++;
		}
		rewind(arquivos[0]);
		rewind(arquivos[1]);
		rewind(arquivos[2]);
		cont = 0;
		a =  fgetc(arquivos[0]);
		b =  fgetc(arquivos[1]);
		c =  fgetc(arquivos[2]);
		i = 1;
		distribuicao(a, b, c, &arquivos, i);
		rewind(arquivos[3]);
		rewind(arquivos[4]);
		rewind(arquivos[5]);
		a =  fgetc(arquivos[3]);
		b =  fgetc(arquivos[4]);
		c =  fgetc(arquivos[5]);
		rewind(arquivos[0]);
		i = 0;		
		distribuicao(a, b, c, &arquivos, i);
		fclose(arquivos[0]);
		fclose(arquivos[1]);
		fclose(arquivos[2]);
		fclose(arquivos[3]);
		fclose(arquivos[4]);
		fclose(arquivos[5]);
		return 0;
}
