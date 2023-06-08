#include <stdio.h>
#include <string.h>

void exibirLocacao(Locacao *vetLoc, int indice)  {
    // Exibir os dados:
    printf("CPF: %s\n",  vetLoc[indice].CPF);
    printf("Codigo: %s\n",   vetLoc[indice].codigo);
    printf("Data de Entrada: %s\n",   vetLoc[indice].data);
    printf("Aluguel: %.2f\n",   vetLoc[indice].aluguel);
}

// Funcao existe_clin_loc
// Verifica se existe alguma locacao com um certo cpf.
//
// Parametros:
//     - vetLoc : ponteiro para o vetor de locacoes.
//     - totLoc : inteiro que registra quantas locacoes
//                estao cadastradas no vetor.
//     - cpf    : string que representa o cpf a procurar.
//
// Retorno:
//     - inteiro : 0 se nao achou.
//                 1 se achou.
//

int existe_clin_loc( Locacao *vetLoc, int totLoc, char cpf[] )
{
    int i;
    
    // Percorre os elementos existentes no vetor (de 0 ate totLoc).
    for(i=0; i<totLoc; i++)
    {
        // Compara o cpf neste elemento do vetor, com o cpf informado.
        // Se achou, retorna 1.
        if ( strcmp(vetLoc[i].CPF, cpf) == 0 )
            return 1;
    }
            
    // Se chegou aqui, nao achou. Retorna 0.
    return 0;
}
//----------------------------------------------------------------------


//
// Funcao existe_imovel_loc
// Verifica se existe locacao em uma certa sigla.
//
// Parametros:
//     - vetLoc : ponteiro para o vetor de locacoes.
//     - totLoc : inteiro que registra quantas locacoes
//                estao cadastradas no vetor.
//     - sigla  : string que representa a sigla a procurar.
//
// Retorno:
//     - inteiro : 0 se nao achou.
//                 1 se achou.
//

int existe_imovel_loc( Locacao *vetLoc, int totLoc, char codigo[] )
{
    int i;
    
    // Percorre os elementos existentes no vetor (de 0 ate totLoc).
    for(i=0; i<totLoc; i++)
    {
        // Compara a sigla neste elemento do vetor, com a sigla informada.
        // Se achou, retorna 1.
        if ( strcmp(vetLoc[i].codigo, codigo) == 0 )
            return 1;
    }
            
    // Se chegou aqui, nao achou. Retorna 0.
    return 0;
}

//----------------------------------------------------------------------

int existe_locacao( Locacao *vetLoc, int totLoc, char cpf[], char codigo[], char data[])
{
    int i;
    
    // Percorre os elementos existentes no vetor (de 0 ate totLocacao).
    for(i=0; i<totLoc; i++)
    {
        // Compara o codigo neste elemento do vetor, com o cpf, codigo e data informados.
        // Se achou, retorna o Indice.
        if ( strcmp(vetLoc[i].CPF, cpf) == 0 ){
        	if ( strcmp(vetLoc[i].codigo, codigo) == 0 ){
        		if ( strcmp(vetLoc[i].data, data) == 0 )
            		return i;
			}
		}
    }
            
    // Se chegou aqui, nao achou. Retorna -1.
    return -1;
}

void incluir_locacao( Cliente *vetClin, int totClin, 
                      Imovel *vetImovel, int totImovel, 
                      Locacao *vetLoc, int *totLoc )
{
    char CPF[12];
    char codigo[12];
    char data[11];
    float aluguel;
    char LIXO[2];
    int i;
    
    
    printf("\nInclusao de Locacao:\n");
    
    if ( *totLoc == TOTAL )
    {
        printf("\n*ERRO* Nao ha espaco para incluir mais um locacao!\n");
    }
    else
    {
        printf("Digite o CPF do Cliente: ");
        gets(CPF);
    
        // Verificar se este CPF existe, usar esse i para verificar se o aluguel é menor que o salario da pessoa la embaixo:
        i = existe_cliente(vetClin, totClin, CPF);
        if ( i == -1 )
        {
            printf("\n* Este CPF nao existe! *\n");
        }
        else
        {
            printf("Digite o codigo do Imovel: ");
            gets(codigo);
            
            // Verificar se este codigo existe:
            if ( existe_imovel(vetImovel, totImovel, codigo) == -1 )
            {
                printf("\n* Este codigo nao existe! *\n");
            }
            else
            {
                printf("Digite a data: ");
                gets(data);
                // Finalmente, verificar se essa locacao ja existe:
                if ( existe_locacao(vetLoc, *totLoc, CPF, codigo, data) != -1 )
                {
                    printf("\n* Esta locacao ja existe! *\n");
                }
                else
                {
                    // Tudo ok, receber aluguel e inserir no vetor:
                    printf("Digite o aluguel: ");
                    scanf("%f%*c", &aluguel);
                    while(aluguel > vetClin[i].salario){
                    	printf("O aluguel e maior que o salario do locador!\n");
                    	printf("Digite um aluguel menor e peca um caucao maior!\n");
                    	scanf("%f%*c", &aluguel);
					}
        
                    strcpy(vetLoc[*totLoc].CPF, CPF);
                    strcpy(vetLoc[*totLoc].codigo, codigo);
                    strcpy(vetLoc[*totLoc].data, data);
                    vetLoc[*totLoc].aluguel = aluguel;
                    
                    // Incrementar o numero de locacoes:
                    (*totLoc)++;
            
                    printf("\n* Locacao inserida com sucesso! *\n");
                }
            }
        }
    }
    
    printf("\nAperte <ENTER> para continuar...");
    gets(LIXO);
}

void alterar_locacao( Cliente *vetClin, int totClin, 
                      Imovel *vetImovel, int totImovel, 
                      Locacao *vetLoc, int *totLoc )
{
    char CPF[12];
    char codigo[12];
    char data[11];
    float aluguel;
    char confirmar;
    char LIXO[2];
    int indice, i;
    
    
    printf("\nAlteracao de Locacao:\n");
    
    printf("Digite o CPF do locador: ");
    gets(CPF);
    printf("Digite o codigo do imovel: ");
    gets(codigo);
    printf("Digite a data de entrada: ");
    gets(data);
    
    // Verificar se esta codigo existe no vetor:
    indice = existe_locacao(vetLoc, *totLoc, CPF, codigo, data);
    
    if ( indice == -1 )
    {
        printf("\n* Esta locacao nao existe! *\n");
    }
    else
    {
    	exibirLocacao(vetLoc, indice);
        printf("\nDeseja alterar o CPF do locador? (y/n): ");
        scanf("%c%*c", &confirmar);
		if (confirmar == 'y') {
        	printf("Digite o CPF de outro locador: ");
        	gets(CPF);
			while(existe_cliente(vetClin, totClin, CPF) == -1) {
	        	printf("CPF nao existe!\n");
	        	printf("Digite um CPF existente: ");
	        	gets(CPF);
        	}
		} else {
			strcpy(CPF, vetLoc[indice].CPF);
		}
		// Usar esse i para verificar o valor do aluguel e comparar com o salario la embaixo
		i = existe_cliente(vetClin, totClin, CPF);
        printf("Deseja alterar o codigo do Imovel? (y/n): ");
        scanf("%c%*c", &confirmar);
		if (confirmar == 'y') {
        	printf("Digite o codigo de outro imovel: ");
        	gets(codigo);
			while(existe_imovel(vetImovel, totImovel, codigo) == -1) {
	        	printf("Codigo nao existe!\n");
	        	printf("Digite um codigo existente: ");
	        	gets(codigo);
        	}
		} else {
			strcpy(codigo, vetLoc[indice].codigo);
		}
        printf("Deseja alterar a data de entrada? (y/n): ");
        scanf("%c%*c", &confirmar);
		if (confirmar == 'y') {
        	printf("Digite a nova data de entrada (dd/mm/aaaa): ");
        	gets(data);
		} else {
			strcpy(data, vetLoc[indice].data);
		}
        printf("Deseja alterar o aluguel? (y/n): ");
        scanf("%c%*c", &confirmar);
		if (confirmar == 'y') {
        	printf("Digite o novo aluguel: ");
        	scanf("%f%*c", &aluguel);
            while(aluguel > vetClin[i].salario){
            	printf("O aluguel e maior que o salario do locador!\n");
            	printf("Digite um aluguel menor e peca um caucao maior!\n");
            	scanf("%f%*c", &aluguel);
			}
		} else {
			aluguel = vetLoc[indice].aluguel;
		}
        
        strcpy( vetLoc[indice].CPF, CPF );
        strcpy( vetLoc[indice].codigo, codigo );
        strcpy( vetLoc[indice].data, data );
        vetLoc[indice].aluguel = aluguel;
            
        printf("\n* Locacao alterada com sucesso!\n");
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}

void apagar_locacao(Locacao *vetLoc, int *totLoc)
{
    char CPF[12];
    char codigo[12];
    char data[11];
    char LIXO[2];
    int indice, i;
    
    printf("\nApagando Locacao:\n");
    
    printf("Digite o CPF do locador: ");
    gets(CPF);
    printf("Digite o codigo do imovel: ");
    gets(codigo);
    printf("Digite a data de entrada: ");
    gets(data);
    
    // Verificar se esta codigo existe no vetor:
    indice = existe_locacao(vetLoc, *totLoc, CPF, codigo, data);
    
    if ( indice == -1 )
    {
        printf("\n* Esta locacao nao existe! *\n");
    }
    else
    {         
        for( i=indice; i<(*totLoc)-1; i++)
        {
            strcpy( vetLoc[indice].CPF, vetLoc[indice+1].CPF );
            strcpy( vetLoc[indice].codigo, vetLoc[indice+1].codigo );
            strcpy( vetLoc[indice].data, vetLoc[indice+1].data );
            vetLoc[indice].aluguel = vetLoc[indice+1].aluguel;
        }
        
        // Decrementa *totLocacao:
        (*totLoc)--;
            
        printf("\n* Locacao apagado com sucesso! *\n");
    }
    printf("\nDigite <ENTER> para continuar...");
    gets(LIXO);
}    


void consultar_locacao(Locacao *vetLoc, int *totLoc)
{
    char CPF[12];
    char codigo[12];
    char data[11];
    char LIXO[2];
    int indice;
    
    printf("\nConsultar Locacao:\n");
    
    printf("Digite o CPF do locador: ");
    gets(CPF);
    printf("Digite o codigo do imovel: ");
    gets(codigo);
    printf("Digite a data de entrada: ");
    gets(data);
    
    // Verificar se esta codigo existe no vetor:
    indice = existe_locacao(vetLoc, *totLoc, CPF, codigo, data);
    
    if ( indice == -1 )
    {
        printf("\n* Esta locacao nao existe! *\n");
    }
    else
    {
        // Tudo ok, exibir os dados:
        exibirLocacao(vetLoc, indice);
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}    


void consultarTodos_locacao(Locacao *vetLoc, int *totLoc)
{
    char LIXO[2];
    int i;
    
    if( (*totLoc) == 0 )
    {
        printf("\nNao ha locacao para exibir!\n");
    }
    else
    {
        printf("\nExibindo todas as locacoes:\n");
    
        for( i=0; i<(*totLoc); i++ )
        {            
			printf("\n-----%d-----\n", i+1);
			exibirLocacao(vetLoc, i);
        }
        
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);  
}
