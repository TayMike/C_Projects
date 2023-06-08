#include <stdio.h>
#include <string.h>

//----------------------------------------------------------------------

//
// Funcao existe_cliente
//
//
// Parametros:
//     - vetClin : ponteiro para o vetor de cliente.
//     - totClin : inteiro que registra quantos clientes
//                 estao cadastrados no vetor.
//     - cpf     : string que representa o cpf a procurar.
//
// Retorno:
//     - inteiro : -1 se nao achou.
//                 o indice onde esta, se achou.

int existe_cliente(Cliente *vetClin, int totClin, char cpf[]) {
    int i;
    
    // Percorre os elementos existentes no vetor (de 0 ate totClin).
    for(i=0; i<totClin; i++)
    {
        // Compara o cpf neste elemento do vetor, com o cpf informado.
        // Se achou, retorna o Indice.
        if (strcmp(vetClin[i].CPF, cpf) == 0 )
            return i;
    }
            
    // Se chegou aqui, nao achou. Retorna -1.
    return -1;
}

void exibirCliente(Cliente *vetClin, int indice)  {
    // Exibir os dados:
    printf("CPF: %s\n",  vetClin[indice].CPF);
    printf("Nome: %s\n", vetClin[indice].nome);
    printf("Salario: %.2f\n", vetClin[indice].salario);
    printf("E-mail: %s\n", vetClin[indice].email);	
}

//----------------------------------------------------------------------

//
// Funcao incluir_cliente
//
// Parametros:
//     - vetClin : ponteiro para o vetor de clientes.
//     - totClin : ponteiro para o inteiro que registra 
//                 quantos clientes estao cadastrados no vetor.

void incluir_cliente( Cliente *vetClin, int *totClin )
{
    char cpf[12];
    char nome[31];
    float salario;
    char email[31];
    char LIXO[2];
    
    
    printf("\nInclusao de Cliente:\n");
    
    // Atencao!
    // Recebemos aqui o endereco de memoria onde esta a variavel totClin.
    // Entao, para acessar o seu conteudo, 
    // precisamos usar o "operador de desreferencia" (*) para acessar seu conteudo.
    
    // Se o vetor chegou no seu limite, indicar erro:
    if ( *totClin == TOTAL )
    {
        printf("\n*ERRO* Nao ha espaco para incluir mais um cliente!\n");
    }
    else
    {
        printf("Digite o CPF do cliente: ");
        gets(cpf);
    
        // Verificar se este CPF ja existe no vetor:
        if (existe_cliente(vetClin, *totClin, cpf) != -1)
        {
            printf("\n* Este CPF ja existe! *\n");
        }
        else
        {
            // Tudo ok, receber os outros dados e inserir os dados no vetor:
            // Nome
            printf("Digite o Nome do cliente: ");
            gets(nome);
			// Salario
			printf("Digite o Salario do cliente: ");
            scanf("%f%*c", &salario);
            // Email
			printf("Digite o E-mail do cliente: ");
            gets(email);

            strcpy( vetClin[*totClin].CPF, cpf );
            strcpy( vetClin[*totClin].nome, nome );
            vetClin[*totClin].salario = salario;
            strcpy( vetClin[*totClin].email, email );
            
            // *totClin acessa o endereco apontado
            // (*totClin) acessa o conteudo apontado por totClin.
            // (*totClin)++ soma 1 nesse conteudo.
        
            (*totClin)++;
            
            printf("\n* Cliente inserido com sucesso! *\n");
        }
    }
    printf("\nDigite <ENTER> para continuar...");
    gets(LIXO);
}


//----------------------------------------------------------------------

//
// Funcao alterar_cliente
//
// Parametros:
//     - vetClin : ponteiro para o vetor de clientes.
//     - totClin : ponteiro para o inteiro que registra 
//                 quantos clientes estao cadastrados no vetor.

void alterar_cliente( Cliente *vetClin, int *totClin )
{
    char cpf[12];
    char nome[31];
    float salario;
    char email[31];
    char confirmar;
    char LIXO[2];
    int indice;
    
    
    printf("\nAlteracao de Cliente:\n");
    
    printf("Digite o CPF do Cliente: ");
    gets(cpf);
    
    // Verificar se este CPF existe no vetor:
    indice = existe_cliente( vetClin, *totClin, cpf );
    
    if ( indice == -1 )
    {
        printf("\n* Este CPF nao existe! *\n");
    }
    else
    {
    	exibirCliente(vetClin, indice);
        // Tudo ok, receber os dados e alterar eles no vetor:
        printf("\nDeseja alterar o Nome do Cliente? (y/n): ");
        scanf("%c%*c", &confirmar);
		if (confirmar == 'y') {
		    printf("Digite o Nome do Cliente: ");
        	gets(nome);
		} else {
			strcpy(nome, vetClin[indice].nome);
		}
        printf("Deseja alterar o Salario do Cliente? (y/n): ");
		scanf("%c%*c", &confirmar);
		if (confirmar == 'y') {
	        printf("Digite o salario do Cliente: ");
	        scanf("%f%*c", &salario);
		} else {
			salario = vetClin[indice].salario;
		}
        printf("Deseja alterar o E-mail do Cliente? (y/n): ");
		scanf("%c%*c", &confirmar);
		if (confirmar == 'y') {
	        printf("Digite o e-mail do Cliente: ");
	        gets(email);
		} else {
			strcpy(email, vetClin[indice].email);
		}
        
        strcpy( vetClin[indice].CPF, cpf );
        strcpy( vetClin[indice].nome, nome );
		vetClin[indice].salario = salario;
		strcpy( vetClin[indice].email, email );
            
        printf("\n* Alteracao realizada com sucesso! *\n");
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}

    
//----------------------------------------------------------------------

//
// Funcao apagar_cliente
//
// Parametros:
//     - vetClin : ponteiro para o vetor de clientes.
//     - totClin : ponteiro para o inteiro que registra 
//                 quantos clientes estao cadastrados no vetor.


void apagar_cliente( Cliente *vetClin, int *totClin, Locacao *vetLoc, int totLoc )
{
    char cpf[12];
    char LIXO[2];
    char confirmar;
    int indice, i;
    
    
    printf("\nApagando Cliente:\n");
    
    printf("Digite o CPF do cliente: ");
    gets(cpf);
    
        // Verifica se existe alguma locacao deste cliente:
    if ( existe_clin_loc( vetLoc, totLoc, cpf ) )
    {
        printf("\n* Este CPF tem locacao! Nao posso apagar! *\n");
    }
    else
	{
	    // Verificar se este CPF existe no vetor:
	    indice = existe_cliente(vetClin, *totClin, cpf);
			
	    if ( indice == -1 )
	    {
	        printf("\n* Este CPF nao existe! *\n");
	    }
	    else
	    {
	        // Tudo ok, apagar o registro.
	        // Lembrando que para apagar um elemento do vetor,
	        // voce precisa "deslocar para a esquerda"
	        // todos os elementos seguintes armazenados no vetor,
	        // isto e, deslocar "pra esquerda" desde o elemento 'indice'+1
	        // ate o elemento (*totClin)-1.
	        // Ao final, decrementar *totClin.
		    exibirCliente(vetClin, indice);
		    printf("Deseja realmente excluir o Cliente? (y/n): ");
		    scanf("%c%*c", &confirmar);
			if (confirmar == 'y') {
		        for( i=indice; i<(*totClin)-1; i++) {
		            strcpy( vetClin[indice].CPF, vetClin[indice+1].CPF );
		            strcpy( vetClin[indice].nome, vetClin[indice+1].nome );
		            vetClin[indice].salario = vetClin[indice+1].salario;
		            strcpy( vetClin[indice].email, vetClin[indice+1].email );
		        }
		        
		        // Decrementa *totClin:
		        (*totClin)--;
		            
		        printf("\n* Cliente apagado com sucesso!\n");		
			} else {
				printf("\n* Cliente NAO foi apagado!\n");
			}
	    }
	    printf("\nDigite <ENTER> para continuar....");
	    gets(LIXO);
	}
}    
    
    
//----------------------------------------------------------------------

//
// Funcao consultar_cliente
//
// Parametros:
//     - vetClin : ponteiro para o vetor de clientes.
//     - totClin : ponteiro para o inteiro que registra 
//                 quantos clientes estao cadastrados no vetor.

void consultar_cliente( Cliente *vetClin, int *totClin )
{
    char cpf[12];
    char LIXO[2];
    int indice;
    
    
    printf("\nConsultar Cliente:\n");
    
    printf("Digite o CPF do cliente: ");
    gets(cpf);
    
    // Verificar se este CPF existe no vetor:
    indice = existe_cliente(vetClin, *totClin, cpf);
    
    if ( indice == -1 )
    {
        printf("\n* Este CPF nao existe! *\n");
    }
    else
    {
    	exibirCliente(vetClin, indice);
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    
    
    
//----------------------------------------------------------------------


//
// Funcao consultarTodos_cliente
//
// Parametros:
//     - vetClin : ponteiro para o vetor de clientes.
//     - totClin : ponteiro para o inteiro que registra 
//                 quantos clientes estao cadastrados no vetor.

void consultarTodos_cliente( Cliente *vetClin, int *totClin )
{
    char LIXO[2];
    int i;
    
    if( (*totClin) == 0 ) {
        printf("\nNao ha clientes a exibir!\n");
    } else {
        printf("\nExibindo todos os clientes:\n");
        for( i=0; i<(*totClin); i++ )
        {         
			printf("\n-----%d-----\n", i+1);
			exibirCliente(vetClin, i);   
        }
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    
