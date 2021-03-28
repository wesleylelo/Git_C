#include <stdio.h>
#include <string.h>
#include "BIBLIO_ORDERACAO_VC.h"
void bubblesort2(unsigned char *v, int n){
	unsigned char aux;
	int i, j;
	for (i = 0; i < n - 1; i++){
		for(j = 0; j < n - i - 1; j++){
			if (v[j] > v[j+1]){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
}
void modificar( unsigned char *v){
	if(v[0] > 122)v[0] = v[0] - 32;
	if(v[1] > 122)v[1] = v[1] - 32;
	if(v[2]>122)v[2]= v[2] - 32;
}
int quant(unsigned char *v){
	int j = 0, i;
	for(i = 0; i < strlen(v); i++){
		if(v[i] > 122) j++;
	}
	return j;
}
int verificar(unsigned char *v){
	if(v[0] > 122 && v[1] > 122 && v[2] > 122){
		return 1;
	} else{
		return 0;
	}
}
int main(){
	unsigned char vect[3], c = ' ', frase[] = "lwkeospajfmcnxbsjdkfrityuop";
	char w,e,s;
	FILE *arquivos[3];
	int cont = 0, i,b, verify = 1, verify2 = 1;
	arquivos[0] = fopen("arquivo1s.txt", "w+");
	arquivos[1] = fopen("arquivo2s.txt", "w+");
	arquivos[2] = fopen("arquivo3s.txt", "w+");
	arquivos[3] = fopen("arquivo4s.txt", "w+");
	vect[0] = frase[0];
	vect[1] = frase[1];
	vect[2] = frase[2];
	
for(i = 3; i < 28; i++){
	b = verificar(&vect);
	if(frase[i] == '\0' && quant(&vect) < 3){
		modificar(&vect);
	}
	if(b){
		if(cont == 0) cont++;
		else if(cont == 1) cont++;
		else cont = 0;
		modificar(&vect);
		if(cont == 1){
			fputc(' ', arquivos[0]);	
		} else if(cont == 0){
			fputc(' ', arquivos[2]);
		} else if(cont == 2){
			fputc(' ', arquivos[1]);
		}
	}
	if(cont == 0){
		bubblesort2(&vect, strlen(vect));
		fputc(vect[0], arquivos[0]);
	if(frase[i] < vect[0] && frase[i] != '\0'){
		vect[0] = frase[i] + 32;
	} else if(frase[i] > vect[0] && frase[i] != '\0') {
		vect[0] = frase[i];
	} else{
		fputc(vect[1], arquivos[0]);
		fputc(vect[2], arquivos[0]);
	}
	} else if(cont == 1){
		bubblesort2(&vect, strlen(vect));
		fputc(vect[0], arquivos[1]);	
		if(frase[i] < vect[0] && frase[i] != '\0'){
			vect[0] = frase[i] + 32;
		} else if(frase[i] > vect[0] && frase[i] != '\0') {
			vect[0] = frase[i];
		} else{
			fputc(vect[1], arquivos[1]);
			fputc(vect[2], arquivos[1]);
		}
	} else {
		bubblesort2(&vect, strlen(vect));
		fputc(vect[0], arquivos[2]);	
		if(frase[i] < vect[0] && frase[i] != '\0'){
			vect[0] = frase[i] + 32;
		} else if(frase[i] > vect[0] && frase[i] != '\0') {
			vect[0] = frase[i];
		} else{
			fputc(vect[1], arquivos[2]);
			fputc(vect[2], arquivos[2]);
		}
	}
	bubblesort2(&vect, 3);	
  }
  rewind(arquivos[0]);
  rewind(arquivos[1]);
  rewind(arquivos[2]);
  	w = fgetc(arquivos[0]);
  	e = fgetc(arquivos[1]);
	s = fgetc(arquivos[2]);
	distribuicao(w,e,s,&arquivos);
	rewind(arquivos[3]);
	w = fgetc(arquivos[0]);
  	e = fgetc(arquivos[1]);
	s = fgetc(arquivos[2]);
	if(w != EOF){
		rewind(arquivos[1]);
		e = fgetc(arquivos[3]);
		while(e != EOF && w != EOF){
			if(e <= w && verify == 1){
				fputc(e, arquivos[1]);
				e = fgetc(arquivos[3]);
				if(e == EOF){
					while(e != EOF){
						fputc(w, arquivos[1]);
						w = fgetc(arquivos[0]);
					}
				}
				continue;
			} else if(w < e && verify2 == 1) {
				fputc(w, arquivos[1]);
				w = fgetc(arquivos[0]);
				if(w == EOF){
					while(e != EOF){
						fputc(e, arquivos[1]);
						e = fgetc(arquivos[3]);
					}
				}
				continue;
			}
		}
	} else if(e != EOF){
		rewind(arquivos[0]);
		w = fgetc(arquivos[3]);
		while(e != EOF && w != EOF){
			if(e <= w && verify == 1){
				fputc(e, arquivos[0]);
				e = fgetc(arquivos[1]);
				if(e == EOF){
					while(w != EOF){
						fputc(w, arquivos[0]);
						w = fgetc(arquivos[3]);
					}
				}
				continue;
			} else if(w < e && verify2 == 1){
				fputc(w, arquivos[0]);
				w = fgetc(arquivos[3]);
				if(w == EOF){
					while(e != EOF){
						fputc(e, arquivos[0]);
						e = fgetc(arquivos[1]);
					}
				}
				continue;
			}
		}
	} else {
		rewind(arquivos[1]);
		rewind(arquivos[3]);
		w = fgetc(arquivos[3]);
		while(s != EOF && w != EOF){
			if(s <= w && verify == 1){
				fputc(s, arquivos[0]);
				s = fgetc(arquivos[2]);
				if(s == EOF){
					while(w != EOF){
						fputc(w, arquivos[0]);
						w = fgetc(arquivos[3]);
					}
				}
				continue;
			} else if(w < s && verify2 == 1) {
				fputc(w, arquivos[0]);
				w = fgetc(arquivos[3]);
				if(w == EOF){
					while(s != EOF){
						fputc(s, arquivos[0]);
						s = fgetc(arquivos[2]);
					}
				}
				continue;
			}
		}
	}
	fclose(arquivos[0]);
	fclose(arquivos[1]);
	fclose(arquivos[2]);
	fclose(arquivos[3]);
  return 0;		
}
