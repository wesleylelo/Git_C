#include <stdio.h>

int enPrimo(int n);

int main(){
	int enesimo, i = 0, n = 2;
	scanf("%d", &enesimo);
	while (i < enesimo){
		if(enPrimo(n)) i++;
		if(i != enesimo) n++;
	}
	printf("Enesimo termo: %d", n);
	return 0;
}


int enPrimo(int n){
	int i;
	if(n == 2) return 1;
	for(i = 2; i < n; i++){
		if (n%i == 0) return 0;
	}
	return 1;
}


