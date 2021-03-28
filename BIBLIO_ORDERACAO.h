#include <stdio.h>
#include <string.h>


void distribuicao(char a, char b, char c, FILE* arquivos[], int i){
	int cont = 0, conta = 3, contb = 3, contc = 3;
while(!(a == EOF && b == EOF && c == EOF)){	
	if(a <= b && a <= c && conta > 0 && contb > 0 && contc > 0){
			if(i){
			if(cont < 9) fputc(a, arquivos[3]);
			else if(cont >= 9 && cont < 18) fputc(a, arquivos[4]);
			else if(cont >= 18 && cont <= 26) fputc(a, arquivos[5]);
			} else fputc(a, arquivos[0]);
			cont++;
			conta--;
			if(i) a = fgetc(arquivos[0]);
			else a = fgetc(arquivos[3]);
			continue;
	} else if(b <= a && b <= c && conta > 0 && contb > 0 && contc > 0){
			if (i){
			if(cont < 9) fputc(b, arquivos[3]);
			else if(cont >= 9 && cont < 18) fputc(b, arquivos[4]);
			else if(cont >= 18 && cont <= 26) fputc(b, arquivos[5]);
			} else fputc(b, arquivos[0]);
			cont++;
			contb--;
			if(i) b = fgetc(arquivos[1]);
			else b = fgetc(arquivos[4]);
			continue;
	} else if(c <= b && c <= a && conta > 0 && contb > 0 && contc > 0){
			if(i){
			if(cont < 9) fputc(c, arquivos[3]);
			else if(cont >= 9 && cont < 18) fputc(c, arquivos[4]);
			else if(cont >= 18 && cont <= 26) fputc(c, arquivos[5]);
			} else fputc(c, arquivos[0]);
			cont++;
			contc--;
			if(i) c = fgetc(arquivos[2]);
			else c = fgetc(arquivos[5]);
			continue;
 	} else if (c <= b && contb > 0 && contc > 0){
 			if(i){
			if(cont < 9) fputc(c, arquivos[3]);
			else if(cont >= 9 && cont < 18) fputc(c, arquivos[4]);
			else if(cont >= 18 && cont <= 26) fputc(c, arquivos[5]);
			} else fputc(c, arquivos[0]);
			cont++;
			contc--;
			
			if(i) c = fgetc(arquivos[2]);
			else c = fgetc(arquivos[5]);
			continue;
	 } else if(b <= c && contb > 0 && contc > 0){
	 		if(i){
	 		if(cont < 9) fputc(b, arquivos[3]);
			else if(cont >= 9 && cont < 18) fputc(b, arquivos[4]);
			else if(cont >= 18 && cont <= 26) fputc(b, arquivos[5]);
			} else fputc(b, arquivos[0]);
			cont++;
			contb--;
			if(i) b = fgetc(arquivos[1]);
			else b = fgetc(arquivos[4]);
			continue;
	 } else if (a <= b && contb > 0 && conta > 0){
	 		if(i){
 			if(cont < 9) fputc(a, arquivos[3]);
			else if(cont >= 9 && cont < 18) fputc(a, arquivos[4]);
			else if(cont >= 18 && cont <= 26) fputc(a, arquivos[5]);
			} else fputc(a, arquivos[0]);
			cont++;
			conta--;
			if(i) a = fgetc(arquivos[0]);
			else a = fgetc(arquivos[3]);
			continue;
	 } else if(b <= a && conta > 0 && contb > 0){
	 		if(i){
	 		if(cont < 9) fputc(b, arquivos[3]);
			else if(cont >= 9 && cont < 18) fputc(b, arquivos[4]);
			else if(cont >= 18 && cont <= 26) fputc(b, arquivos[5]);
			} else fputc(b, arquivos[0]);
			cont++;
			contb--;
			if(i) b = fgetc(arquivos[1]);
			else b = fgetc(arquivos[4]);
			continue;
	 } else if (a <= c && contc > 0 && conta > 0){
 			if(i){
			if(cont < 9) fputc(a, arquivos[3]);
			else if(cont >= 9 && cont < 18) fputc(a, arquivos[4]);
			else if(cont >= 18 && cont <= 26) fputc(a, arquivos[5]);
			} else fputc(a, arquivos[0]);
			cont++;
			conta--;
			if(i) a = fgetc(arquivos[0]);
			else a = fgetc(arquivos[3]);
			continue;
	 } else if(c <= a && conta > 0 && contc > 0){
	 		if(i){
			if(cont < 9) fputc(c, arquivos[3]);
			else if(cont >= 9 && cont < 18) fputc(c, arquivos[4]);
			else if(cont >= 18 && cont <= 26) fputc(c, arquivos[5]);
			} else fputc(c, arquivos[0]);
			cont++;
			contc--;
			if(i) c = fgetc(arquivos[2]);
			else c = fgetc(arquivos[5]);
			continue;
	 } else if(conta > 0){
	 		if(i){
			if(cont < 9) fputc(a, arquivos[3]);
			else if(cont >= 9 && cont < 18) fputc(a, arquivos[4]);
			else if(cont >= 18 && cont <= 26) fputc(a, arquivos[5]);
			} else fputc(a, arquivos[0]);
			cont++;
			conta--;			
			if(i) a = fgetc(arquivos[0]);
			else a = fgetc(arquivos[3]);
			continue;
	 } else if(contb > 0){
	 		if(i){
			if(cont < 9) fputc(b, arquivos[3]);
			else if(cont >= 9 && cont < 18) fputc(b, arquivos[4]);
			else if(cont >= 18 && cont <= 26) fputc(b, arquivos[5]);
			} else fputc(b, arquivos[0]);
			cont++;
			contb--;			
			if(i) b = fgetc(arquivos[1]);
			else b = fgetc(arquivos[4]);
			continue;
	 } else if(contc > 0){
	 		if(i){
			if(cont < 9) fputc(c, arquivos[3]);
			else if(cont >= 9 && cont < 18) fputc(c, arquivos[4]);
			else if(cont >= 18 && cont <= 26) fputc(c, arquivos[5]);
			} else fputc(c, arquivos[0]);
			cont++;
			contc--;			
			if(i) c = fgetc(arquivos[2]);
			else c = fgetc(arquivos[5]);
			continue;
	 	}
	 	if (conta == 0 && contb == 0 && contc == 0){
	 		conta = 3;
	 		contb = 3;
	 		contc = 3;
		 }
	}
}
