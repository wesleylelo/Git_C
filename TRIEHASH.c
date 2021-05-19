#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define QUANTY 101

 

typedef struct tp_no {
    char placa[10], cor[8];
    double preco;
    struct tp_no* filhos[QUANTY];
    int eh_folha;
} tp_no;
tp_no f[QUANTY];


tp_no* cria_no(char* placa, char* cor, double preco) {
    tp_no* no = (tp_no*) malloc (sizeof(tp_no));
    int i;
    if (no != NULL) {
    	no->eh_folha = 0;
    	strcpy(no->placa,placa);
    	strcpy(no->cor,cor);
    	no->preco = preco;
	    for (i=0; i<QUANTY; i++)
    	    no->filhos[i] = NULL;
	}
    return no;
}
int string_int(char* k){
	int i, total = 0;
	for(i = 0; i < strlen(k); i++)
		total += k[i];
	return total;
}
int hash(int c){
	return c%QUANTY;
}
tp_no* insere_no_trie(tp_no* raiz, int c, tp_no* i) {
    tp_no* no = raiz;

    	while(1){
    		printf("%d", c);
        	if (no->filhos[c] == NULL) {
            	printf("No da arvore nao tem colisao\n");
				no->filhos[c] = cria_no(i->placa,i->cor,i->preco);
            	break;
        	}
        printf("No da arvore tem colisao\n");
        printf("Essa e a placa de colisao %s\n",no->placa);
        no = no->filhos[c];
    	}
    no->eh_folha = 1;
    return raiz;
}


int main(){
	int a;
	
	tp_no* c;
	char placa[20];
	char cor[8];
	double preco;
	int i = 1;
	while(i){
		printf("Digite a placa\n");
		scanf("%s", placa);
		printf("Digite a cor\n");
		scanf("%s", cor);
		printf("Digite o preco\n");
		scanf("%lf", &preco);
		c = cria_no(&placa,&cor,preco);
		if(f[hash(string_int(&c->placa))].eh_folha == 1){
			printf("Esse hash tem colisao\n");
			insere_no_trie(&f[hash(string_int(c->placa))],hash(string_int(c->placa)),c);
		}else{
			printf("Esse hash nao tem colisao\n");
			strcpy(f[hash(string_int(&c->placa))].cor,c->cor);
			strcpy(f[hash(string_int(&c->placa))].placa,c->placa);
			f[hash(string_int(&c->placa))].preco = c->preco;
			f[hash(string_int(&c->placa))].eh_folha = 1;
		}
	scanf("%d", &i);
	getchar();
	}
	return 0;
}
