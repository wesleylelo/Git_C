#include <stdio.h>
#include <string.h>

void distribuicao( unsigned char a, unsigned char b, unsigned char c, FILE* arquivos[]){
	int conta = 1, contb = 1, contc = 1;
	
while(!(a == EOF && b == EOF && c == EOF)){	
printf("%d %d %d", a, b, c);
	if(a <= b && a <= c && conta == 1 && contb == 1 && contc == 1){
			fputc(a, arquivos[3]);
			a = fgetc(arquivos[0]);
			if(a != ' ') {
				continue;
			}else {
				conta = 0;
			}
			if(a == EOF) conta = 0;
	} else if(b <= a && b <= c && conta == 1 && contb == 1 && contc == 1){
			fputc(b, arquivos[3]);
			b = fgetc(arquivos[1]);
			if(b != ' ') {
				continue;
			}else {
				contb = 0;
			}
			if(b == EOF) contb = 0;
	} else if(c <= b && c <= a && conta == 1 && contb == 1 && contc == 1){
			fputc(c, arquivos[3]);
			c = fgetc(arquivos[2]);
			if(c != ' ') {
				continue;
			}else {
				contc = 0;
			}
			if(c == EOF) contc = 0;
 	} else if (c <= b && contb == 1 && contc == 1){
 			fputc(c, arquivos[3]);
			c = fgetc(arquivos[2]);
			if(c != ' ') {
				continue;
			}else {
				contc = 0;
			}
			if(c == EOF) contc = 0;
	 } else if(b <= c && contb == 1 && contc == 1){
	 		fputc(b, arquivos[3]);
			b = fgetc(arquivos[1]);
			if(b != ' ') {
				continue;
			}else {
				contb = 0;
			}
			if(b == EOF) contb = 0;
	 } else if (a <= b && contb == 1 && conta == 1){
	 		fputc(a, arquivos[3]);
			a = fgetc(arquivos[0]);
			if(a != ' ') {
				continue;
			}else {
				conta = 0;
			}
			if(a == EOF) conta = 0;
	 } else if(b <= a && conta == 1 && contb == 1){
	 		fputc(b, arquivos[3]);
			b = fgetc(arquivos[1]);
			if(b != ' ') {
				continue;
			}else {
				contb = 0;
			}
			if(b == EOF) contb = 0;
	 } else if (a <= c && contc == 1 && conta == 1){
 			fputc(a, arquivos[3]);
			a = fgetc(arquivos[0]);
			if(a != ' ') {
				continue;
			}else {
				conta = 0;
			}
			if(a == EOF) conta = 0;
	 } else if(c <= a && conta == 1 && contc == 1){
	 		fputc(c, arquivos[3]);
			c = fgetc(arquivos[2]);
			if(c != ' ') {
				continue;
			}else {
				contc = 0;
			}
			if(c == EOF) contc = 0;
	 } else if(conta == 1 && contb == 0 && contc == 0){
	 		while(a != ' '){
	 			fputc(a, arquivos[3]);
	 			a = fgetc(arquivos[0]);
	 			if(a == EOF) {
					conta = 0;
					break;
				}
			}
	 } else if(contb == 1 && conta == 0 && contc == 0){
	 		while(b != ' '){
	 			fputc(b, arquivos[3]);
	 			b = fgetc(arquivos[1]);
	 			if(b == EOF) {
					contb = 0;
					break;
				}
			}
	 } else if(contc == 1 && contb == 0 && conta == 0){
	 		while(c != ' '){
	 			fputc(c, arquivos[3]);
	 			c = fgetc(arquivos[2]);
	 			if(c == EOF) {
					contc = 0;
					break;
				}
			}
	 	}
	 	if(a == ' ' && b == ' ' && c == ' '){
	 		printf("AAAAAAAAAAAAAAA");
	 		a = fgetc(arquivos[0]);
	 		b = fgetc(arquivos[1]);
	 		c = fgetc(arquivos[2]);
	 		conta = 1;
	 		contb = 1;
	 		contc = 1;
		 }
		
		 printf("%d %d %d", a, b, c);
		 if(a == EOF && b == EOF){
		 	c = EOF;
		 } else if(c == EOF && b == EOF){
		 	a = EOF;
		 } else if(c == EOF && a == EOF){
		 	b = EOF;
		 }
	}
}
