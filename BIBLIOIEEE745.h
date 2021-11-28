int* decimaltobinario(int num, int precisao, int* expoente){

	int* vector_binario = malloc(sizeof(int) * precisao);
	zerar_vector(vector_binario, precisao);
	int* vector_binario_verdadeiro = malloc(sizeof(int) * precisao);
	zerar_vector(vector_binario_verdadeiro, precisao);
	int i = 0;
while(num > 0)
	{
		vector_binario[i] = num % 2;
		i++;
		num = (num / 2);
	
	}
	if(expoente != NULL)
		*expoente = i - 1;
	int j, l = 0;
	if(expoente != NULL){
	for(j = i - 2; j >= 0; j--){
		vector_binario_verdadeiro[l] = vector_binario[j];
		l++;
	}
	}
	return vector_binario_verdadeiro;
	    

}
int *fracionariotobinario(double num,int precisao){

	int* vector_binario = malloc(sizeof(int) * precisao);
	zerar_vector(vector_binario, precisao);
	int i = 0;

	while (num != 0.0) {
        	num *= 2;
        	int resto = (int)num;
        	num -= resto;
		vector_binario[i] = resto;
		i++;
	}
	
	return vector_binario;
}


void zerar_vector(int* vector, int precisao){
	int i;
	for(i = 0; i < precisao; i++){
		vector[i] = 2;
	}
}
int* mantissa(int* vector_inteiro, int* vector_fracionado, int precisao ){
	int* vector_binario = malloc(sizeof(int) * precisao);
	zerar_vector(vector_binario, precisao);
int i, j = 0;
for(i = 0; vector_inteiro[i]!= 2; i++){
	vector_binario[j] = vector_inteiro[i];
	printf("%d", vector_inteiro[i]);
	j++;
}
for(i = 0; (i < sizeof(vector_fracionado)/sizeof(vector_fracionado[0])); i++){
	vector_binario[j] = vector_fracionado[i];
	j++;
}
return vector_binario;
}
