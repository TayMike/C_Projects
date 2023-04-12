#include <stdio.h>

int main(){
	int fatorial;
	int i = 1;
	int resultado = 1;
	printf("Digite um fatorial maior que 0:\n");
	scanf("%d%*c", &fatorial);
	if(fatorial == 0)
		printf("\nO fatorial de %d é: %d", fatorial, resultado);
	else{
		while(i<=fatorial){
			resultado = resultado * i;
			i++;
		}
		printf("\nO fatorial de %d é: %d", fatorial, resultado);
	}
}
