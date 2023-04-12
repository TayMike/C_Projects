#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int buscaBinario(int vetor[], int elemento, int inicio, int fim);

int main(){	

	//Declarar variáveis:
	int vetor[500];
	int procurarNumero;
	int flag = 0, flagOrd = 0;
	int i, j, aux;
	int escolherModo;
	int inicio = 0, fim = 499;
	
	//Declarar números aleatórios:
	srand(time(NULL));
	for(i=0; i<500; i++){
		vetor[i] = ( rand() % 500 );
	}
	
	//Solicitar para o usuário colocar o número que quer encontrar:
	printf("Colocar um número inteiro: ");
	scanf("%d%*c", &procurarNumero);
	
	//Criando o laço de repetição para achar o número:
	
	//Colocando em sequência por Bubble Sort:
	for(i=0; i<500; i++){
		flagOrd = 0;
		for(j=0; j<499; j++){
			if(vetor[j] > vetor[j+1]){
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
				flagOrd = 1;
			}
		}
		if(!flagOrd) break;
	}
	
	//Escolhendo o modo de busca:
	printf("Escolha o modo de busca (Sequencial: 0 e Binário: 1): ");
	scanf("%d%*c", &escolherModo);
	
	if(escolherModo == 0){
		
		//Modo Sequencial:
		for(i=0; i<500; i++){
			if(vetor[i] == procurarNumero){
				flag = i;
				break;
			}
		}
		
	} else {
	
		//Modo Binário:
		flag = buscaBinario(vetor, procurarNumero, inicio, fim);
	}
	
	//Mostrar todos os números na tela usando j, pois a variável i está em uso no final:
	for(j=0; j<500; j++)
		printf("%d, ", vetor[j]);
	
	//Mostrando se pertence ou não ao vetor o número solicitado:
	if(flag != 0)
		printf("\nO número foi encontrado no vetor[%d]!", flag);
	else
		printf("\nO número NÃO foi encontrado!");
}


// Criando busca Binário recursiva:
int buscaBinario(int vetor[], int elemento, int inicio, int fim){
	
	//Declarar variáveis:
	int meio;
	
	//Modo Binário recursivo:
	if(inicio > fim)
		return 0;
	else{
		meio = (inicio + fim)/2;
		if(elemento == vetor[meio])
			return meio;
		else{
			if(elemento > vetor[meio])
				buscaBinario(vetor, elemento, meio+1, fim);
			else
				buscaBinario(vetor, elemento, inicio, meio-1);
		}
	}
}
