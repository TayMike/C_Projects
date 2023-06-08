#include <string.h>

void relatorioTipo(Cliente *vetClin, int totClin, Imovel *vetImovel, int totImovel, Locacao *vetLoc, int totLoc){
    char tipo[12];
    int i, ind, indice, quantidade = 0;
    printf("Escolha um tipo de imovel (comercial/residencial): ");
    gets(tipo);
    for(i = 0; i<totLoc; i++){
    	for(ind = 0; ind<totImovel; ind++){
			if(strcmp(vetImovel[ind].codigo, vetLoc[i].codigo) == 0){
				if(strcmp(vetImovel[ind].tipo, tipo) == 0){
					printf("\n-----%d-----\n", quantidade+1);
					printf("* Cliente *\n");
					exibirCliente(vetClin, existe_cliente(vetClin, totClin, vetLoc[i].CPF));
					printf("* Imovel *\n");
					exibirImovel(vetImovel, ind);
					printf("* Locacao *\n");
					exibirLocacao(vetLoc, i);
					quantidade++;
				}
			}
		}
	}
	if(quantidade == 0)
		printf("\nNao ha informacao para ser mostrada!\n");
}

void relatorioData(Cliente *vetClin, int totClin, Imovel *vetImovel, int totImovel, Locacao *vetLoc, int totLoc){
    char data1[11];
    char data2[11];
    char data3[11];
    int i, ind, indice, quantidade = 0;
    printf("Digite a data inicial (dd/mm/aaaa): ");
    gets(data1);
    printf("Digite a data final (dd/mm/aaaa): ");
    gets(data2);
    // Gerando variáveis struct tm:
    struct tm tm1 = parse_date(data1);
    struct tm tm2 = parse_date(data2);
    // Converte as variáveis para valores de tempo
    time_t t1 = mktime(&tm1);
    time_t t2 = mktime(&tm2);
    for(i = 0; i<totLoc; i++){
    	strcpy(data3, vetLoc[i].data);
    	struct tm tm3 = parse_date(data3);
    	time_t t3 = mktime(&tm3);
    	if ( (difftime(t3, t1) >= 0) && (difftime(t3,t2) <= 0) ){
			printf("\n-----%d-----\n", quantidade+1);
			printf("* Cliente *\n");
			exibirCliente(vetClin, existe_cliente(vetClin, totClin, vetLoc[i].CPF));
			printf("* Imovel *\n");
			exibirImovel(vetImovel, existe_imovel(vetImovel, totImovel, vetLoc[i].codigo));
			printf("* Locacao *\n");
			exibirLocacao(vetLoc, i);
			quantidade++;	
		}
	}
	if(quantidade == 0)
		printf("\nNao ha informacao para ser mostrada!\n");
}
