#include <stdio.h>

// Verificardor de número primo

int main(){
	
	//Declarar variáveis:
	int number;
	int flag = 0;
	
	printf("Digite um numero maior que 1:\n");
	scanf("%d%*c", &number);
	if(number == 2)
		printf("\nO numero e primo");
	else{
		for(int i=2; i<number; i++){
			if (number % i == 0)
				flag = 1;
		}
		if(flag == 0)
			printf("\nO numero e primo");
		else
			printf("\nO numero nao e primo");
	}
}
