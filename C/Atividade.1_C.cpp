#include <stdio.h>

int main(){
		
	// Variáveis para os dados que serão digitados:
	int idade;
	float peso, altura;
	// Variáveis para os cálculos:
	int qtdMenor18 = 0, pesoAcima80 = 0;
	float mediaIdade = 0, mediaAltura = 0;

	for(int time=1; time<=2; time++){
		mediaIdade = 0;
		for(int jog=1; jog<=5; jog++){
			printf("Time %d - Jogador %d:\n", time, jog);
			printf("Idade: ");
			scanf("%d%*c", &idade);
			printf("Peso: ");
			scanf("%f%*c", &peso);
			printf("Altura: ");
			scanf("%f%*c", &altura);
			mediaIdade = mediaIdade + idade;
			mediaAltura = mediaAltura + altura;
			if (idade < 18)
				qtdMenor18++;
			if (peso > 80)
				pesoAcima80++;
		}
		mediaIdade = mediaIdade / 5;
		printf("\nA media de idade desse time e: %.2f\n\n", mediaIdade);
	}
	printf("\nQuantidade de jogadores com menos de 18 anos: %d", qtdMenor18);
	printf("\nAltura media dos jogadores: %.2f", mediaAltura/10);
	float divisao = (float) pesoAcima80/10;
	float resultado = divisao*100;
	printf("\nPorcentagem de jogadores com mais de 80 kilos: %.2f\n\n", resultado);
}
