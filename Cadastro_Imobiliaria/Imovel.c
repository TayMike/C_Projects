#include <stdio.h>
#include <string.h>

//----------------------------------------------------------------------

int existe_imovel( Imovel *vetImovel, int totImovel, char codigo[])
{
    int i;
    
    // Percorre os elementos existentes no vetor (de 0 ate totImovel).
    for(i=0; i<totImovel; i++)
    {
        // Compara o codigo neste elemento do vetor, com o codigo informado.
        // Se achou, retorna o Indice.
        if ( strcmp(vetImovel[i].codigo, codigo) == 0 )
            return i;
    }
            
    // Se chegou aqui, nao achou. Retorna -1.
    return -1;
}

void exibirImovel(Imovel *vetImovel, int indice)  {
    // Exibir os dados:
    printf("Codigo: %s\n",  vetImovel[indice].codigo);
    printf("Descricao: %s\n", vetImovel[indice].descricao);
    printf("Endereco: %s\n", vetImovel[indice].endereco);
    printf("Tipo: %s\n", vetImovel[indice].tipo);
}

void incluir_imovel( Imovel *vetImovel, int *totImovel )
{
    char codigo[12];
    char descricao[31];
    char endereco[31];
    char tipo[12];
    char LIXO[2];
    
    
    printf("\nInclusao de Imovel:\n");
    
    if ( *totImovel == TOTAL )
    {
        printf("\n*ERRO* Nao ha espaco para incluir mais um imovel!\n");
    }
    else
    {
        printf("Digite o Codigo do imovel: ");
        gets(codigo);
    
        // Verificar se este codigo ja existe no vetor:
        if ( existe_imovel(vetImovel, *totImovel, codigo) != -1 )
        {
            printf("\n* Este codigo ja existe!*\n");
        }
        else
        {
            // Tudo ok, receber os dados e inserir eles no vetor:
            
            printf("Digite a Descricao do imovel: ");
            gets(descricao);
            printf("Digite o Endereco do imovel: ");
            gets(endereco);
            printf("Digite o Tipo do imovel (comercial/residencial): ");
            gets(tipo);
        
            strcpy( vetImovel[*totImovel].codigo, codigo );
            strcpy( vetImovel[*totImovel].descricao, descricao );
            strcpy( vetImovel[*totImovel].endereco, endereco );
            strcpy( vetImovel[*totImovel].tipo, tipo );
       
            (*totImovel)++;
            
            printf("\n* Imovel inserido com sucesso!\n");
        }
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}


void alterar_imovel( Imovel *vetImovel, int *totImovel )
{
    char codigo[12];
    char descricao[31];
    char endereco[31];
    char tipo[12];
    char confirmar;
    char LIXO[2];
    int indice;
    
    
    printf("\nAlteracao de Imovel:\n");
    
    printf("Digite a codigo do imovel: ");
    gets(codigo);
    
    // Verificar se esta codigo existe no vetor:
    indice = existe_imovel(vetImovel, *totImovel, codigo);
    
    if ( indice == -1 )
    {
        printf("\n* Este Imovel nao existe! *\n");
    }
    else
    {
    	exibirImovel(vetImovel, indice);
        // Tudo ok, receber os dados e alterar eles no vetor:
        printf("\nDeseja alterar a Descricao do Imovel? (y/n): ");
        scanf("%c%*c", &confirmar);
		if (confirmar == 'y') {
        	printf("Digite a Descricao do imovel: ");
        	gets(descricao);
		} else {
			strcpy(descricao, vetImovel[indice].descricao);
		}
        printf("Deseja alterar a Endereco do Imovel? (y/n): ");
        scanf("%c%*c", &confirmar);
		if (confirmar == 'y') {
        	printf("Digite o Endereco do imovel: ");
        	gets(endereco);
		} else {
			strcpy(endereco, vetImovel[indice].endereco);
		}
        printf("Deseja alterar o Tipo do Imovel? (y/n): ");
        scanf("%c%*c", &confirmar);
		if (confirmar == 'y') {
        	printf("Digite o Tipo do imovel (comercial/residencial): ");
        	gets(tipo);
		} else {
			strcpy(tipo, vetImovel[indice].tipo);
		}
        
        strcpy( vetImovel[indice].codigo, codigo );
        strcpy( vetImovel[indice].descricao, descricao );
        strcpy( vetImovel[indice].endereco, endereco );
        strcpy( vetImovel[indice].tipo, tipo );
            
        printf("\n* Alteracao realizada com sucesso! *\n");
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}


void apagar_imovel( Imovel *vetImovel, int *totImovel, Locacao *vetLoc, int totLoc  )
{
    char codigo[12];
    char LIXO[2];
    int indice, i;
    char confirmar;
    
    printf("\nApagando Imovel:\n");
    
    printf("Digite o codigo do imovel: ");
    gets(codigo);
    
    // Verifica se existe alguma locacao deste imovel:
    if ( existe_imovel_loc(vetLoc, totLoc, codigo) )
    {
        printf("\n* Este imovel tem locacao! Nao posso apagar! *\n");
    }
    else
    {        
    
	    // Verificar se esta codigo existe no vetor:
	    indice = existe_imovel(vetImovel, *totImovel, codigo);
	    
	    if ( indice == -1 )
	    {
	        printf("\n* Este codigo nao existe!*\n");
	    }
	    else
	    {   
			exibirImovel(vetImovel, indice);      
	        printf("Deseja realmente excluir o Imovel? (y/n): ");
	        scanf("%c%*c", &confirmar);
			if (confirmar == 'y') {
				for( i=indice; i<(*totImovel)-1; i++) {
		            strcpy( vetImovel[indice].codigo, vetImovel[indice+1].codigo );
		            strcpy( vetImovel[indice].descricao, vetImovel[indice+1].descricao );
		            strcpy( vetImovel[indice].endereco, vetImovel[indice+1].endereco );
		            strcpy( vetImovel[indice].tipo, vetImovel[indice+1].tipo );
				}
				
				// Decrementa *totImovel:
		        (*totImovel)--;
		            
		        printf("\n* Imovel apagado com sucesso!\n");
			} else {
				printf("\n* Imovel NAO foi apagado!\n");
			}
	    }
	    printf("\nDigite <ENTER> para continuar....");
	    gets(LIXO);
	}
    
}    


void consultar_imovel( Imovel *vetImovel, int *totImovel )
{
    char codigo[12];
    char LIXO[2];
    int indice;
    
    
    printf("\nConsultar Imovel:\n");
    
    printf("Digite o codigo do imovel: ");
    gets(codigo);
    
    // Verificar se esta codigo existe no vetor:
    indice = existe_imovel(vetImovel, *totImovel, codigo);
    
    if ( indice == -1 )
    {
        printf("\n* Este codigo nao existe! *\n");
    }
    else
    {
        // Tudo ok, exibir os dados:
        exibirImovel(vetImovel, indice); 
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    


void consultarTodos_imovel( Imovel *vetImovel, int *totImovel ) {
    char LIXO[2];
    int i;
    
    if( (*totImovel) == 0 ) {
        printf("\nNao ha imovel a exibir!\n");
    } else {
        printf("\nExibindo todos os imoveis:\n");
    
        for( i=0; i<(*totImovel); i++ ) {            
			printf("\n-----%d-----\n", i+1);
			exibirImovel(vetImovel, i);
        }
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    
    
    
    
    
    
    
    
    
    
