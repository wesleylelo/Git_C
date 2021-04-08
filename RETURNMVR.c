int vect(int v[], int i, int maior){
	if(i < 0) return maior;
	else {
		if(maior < v[i]){
			maior = v[i];
			i--;
			return vect(v, i, maior);
		}else {
			i--;
			return vect(v, i, maior);
		}
	}
}





int main(){
int v[] = {0,5,100,6,3,7,1000,56,999,5241,66666,7412,5874};
int n = vect(v, sizeof(v)/sizeof(int) - 1, v[sizeof(v)/sizeof(int) - 1]);
printf("%d", n);
return 0;
}
