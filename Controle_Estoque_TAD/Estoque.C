#include <stdio.h>
#include <string.h>

//----------------------------------------------------------------------

void exibirProduto(Produto produto)  {
	// Exibir os dados:
    printf("Codigo: %s\n",  produto.codigo);
    printf("Nome: %s\n", produto.nome);
    printf("Preco: %lf\n", produto.preco);
    printf("Quantidade: %d\n", produto.quantidade);
}

void incluir_produto(t_lista *lista)
{
	char codigo[15];
	Produto produto;
    char LIXO[2];
    
    
    printf("\nInclusao de Produto:\n");
    
    
    if (cheia(lista))
    {
        printf("\n*ERRO* Nao ha espaco para incluir mais um produto!\n");
    }
    else
    {
        printf("Digite o codigo do produto: ");
        gets(codigo);
    	
    	produto = consultarProduto(lista, codigo);
    	
        // Verificar se este codigo ja existe na lista:
        if ( produto.flag == 1 )
        {
            printf("\n* Este codigo ja existe!*\n");
        }
        else
        {
            // Tudo ok, receber os dados e inserir eles na lista:
            
            printf("Digite o nome do produto: ");
            gets(produto.nome);
            printf("Digite o preco do produto: ");
            scanf("%lf", &produto.preco);
            printf("Digite a quantidade do produto: ");
            scanf("%d", &produto.quantidade);
        
            strcpy( produto.codigo, codigo );
            produto.flag = 1;
       
            inserirFim(lista, produto);
            
            printf("\n* Produto inserido com sucesso!\n");
        }
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}


void alterar_produto(t_lista *lista)
{
	char codigo[15];
    char confirmar;
    char LIXO[2];
    Produto produto;
    
    
    printf("\nAlteracao de produto:\n");
    
    printf("Digite o codigo do produto: ");
    gets(codigo);
    
    // Verificar se esta codigo existe na lista:
    produto = consultarProduto(lista, codigo);
    
    if ( produto.flag == 0 )
    {
        printf("\n* Este produto nao existe! *\n");
    }
    else
    {
    	exibirProduto(produto);
        // Tudo ok, receber os dados e alterar eles no vetor:
        printf("\nDeseja alterar o nome do produto? (y/n): ");
        scanf("%c%*c", &confirmar);
		if (confirmar == 'y') {
        	printf("Digite o nome do produto: ");
        	gets(produto.nome);
		}
        printf("Deseja alterar o preco do produto? (y/n): ");
        scanf("%c%*c", &confirmar);
		if (confirmar == 'y') {
        	printf("Digite o preco do produto: ");
        	scanf("%lf", &produto.preco);
		}
        printf("Deseja alterar a quantidade do produto? (y/n): ");
        scanf("%c%*c", &confirmar);
		if (confirmar == 'y') {
        	printf("Digite a quantidade do produto: ");
        	scanf("%d", &produto.quantidade);
		}
        
        atualizarProduto(lista, produto);
        
        printf("\n* Alteracao realizada com sucesso! *\n");
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}


void apagar_produto(t_lista *lista)
{
	Produto produto;
    char codigo[15];
    char LIXO[2];
    char confirmar;
    
    printf("\nApagando Produto:\n");
    
    printf("Digite o codigo do produto: ");
    gets(codigo);        
    
    // Verificar se esta produto existe na lista:
    produto = consultarProduto(lista, codigo);
	if ( produto.flag == 0 )
    {
        printf("\n* Este codigo nao existe!*\n");
    }
    else
    {   
		exibirProduto(produto);
        printf("Deseja realmente excluir o produto? (y/n): ");
        scanf("%c%*c", &confirmar);
		if (confirmar == 'y') {
			removerIndice(lista, consultarProdutoIndice(lista, codigo));
	        printf("\n* Produto apagado com sucesso!\n");
		} else {
			printf("\n* Produto NAO foi apagado!\n");
		}
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}    


void consultar_produto(t_lista *lista)
{
    char codigo[12];
    char LIXO[2];
    Produto produto;
    
    printf("\nConsultar Produto:\n");
    
    printf("Digite o codigo do produto: ");
    gets(codigo);
    
    // Verificar se esta codigo existe na lista:
    produto = consultarProduto(lista, codigo);
    
    if ( produto.flag == 0 )
    {
        printf("\n* Este codigo nao existe! *\n");
    }
    else
    {
        // Tudo ok, exibir os dados:
        exibirProduto(produto);
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    


void consultarTodos_produto(t_lista *lista) {
	
    char LIXO[2];
    
    if( vazia(lista) == 1 ) {
        printf("\nNao ha produto para exibir!\n");
    } else {
        printf("\nExibindo todos os produtos:\n");
    
        for(int i=0; i<lista->n; i++ ) {
			printf("\n-----%d-----\n", i+1);
			exibirProduto(lista->itens[i]);
        }
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}
