#include <stdio.h>

int main(){
	int i, n = 1, m;
	float valor, soma = 0;
	printf("Digite um número positivo e maior que 0: \n");
	scanf("%d%*c", &i);
	while(n<=i){
		m = (n*2)-1;
		printf("Numerador: %d - Denominador: %d\n", n,m);
		valor = (float) n/m;
		soma = soma + valor;
		printf("Soma: %f\n", soma);
		n++;
	}
	printf("\n%f", soma);
}
