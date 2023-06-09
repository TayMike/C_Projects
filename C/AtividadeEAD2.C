#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int buscaBinario(int vetor[], int elemento, int inicio, int fim);

int main(){	

	//Declarar vari�veis:
	int vetor[500];
	int procurarNumero;
	int flag = 0, flagOrd = 0;
	int i, j, aux;
	int escolherModo;
	int inicio = 0, fim = 499;
	
	//Declarar n�meros aleat�rios:
	srand(time(NULL));
	for(i=0; i<500; i++){
		vetor[i] = ( rand() % 500 );
	}
	
	//Solicitar para o usu�rio colocar o n�mero que quer encontrar:
	printf("Colocar um n�mero inteiro: ");
	scanf("%d%*c", &procurarNumero);
	
	//Criando o la�o de repeti��o para achar o n�mero:
	
	//Colocando em sequ�ncia por Bubble Sort:
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
	printf("Escolha o modo de busca (Sequencial: 0 e Bin�rio: 1): ");
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
	
		//Modo Bin�rio:
		flag = buscaBinario(vetor, procurarNumero, inicio, fim);
	}
	
	//Mostrar todos os n�meros na tela usando j, pois a vari�vel i est� em uso no final:
	for(j=0; j<500; j++)
		printf("%d, ", vetor[j]);
	
	//Mostrando se pertence ou n�o ao vetor o n�mero solicitado:
	if(flag != 0)
		printf("\nO n�mero foi encontrado no vetor[%d]!", flag);
	else
		printf("\nO n�mero N�O foi encontrado!");
}


// Criando busca Bin�rio recursiva:
int buscaBinario(int vetor[], int elemento, int inicio, int fim){
	
	//Declarar vari�veis:
	int meio;
	
	//Modo Bin�rio recursivo:
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
