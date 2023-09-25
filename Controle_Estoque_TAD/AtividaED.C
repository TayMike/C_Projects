#include <stdio.h>
#include "Estruturas.c"
#include "Prototipos.c"
#include "Lista.c"
#include "Estoque.c"
#include "Relatorio.c"

void submenu(char *nomeMenu) {
    printf("\n=== Submenu %s ===\n", nomeMenu);
    printf("1. Incluir\n");
    printf("2. Alterar\n");
    printf("3. Excluir\n");
    printf("4. Consultar\n");
    printf("5. Consultar todos\n");
    printf("6. Voltar ao menu anterior\n");
    printf("\nEscolha uma opcao: ");
}

int main()
{   
	// Criando a lista;
	t_lista *lista;
	lista = criarLista(TOTAL);
	
    // Menus de opcoes:
    int opcao_principal, opcao_submenu;
    
    char subMenuNome[15];
    
	// Carregando arquivo, caso exista:
    FILE *arquivo;
    arquivo = fopen("Estoque.dat", "rb");
    if(arquivo != NULL)
    {
        // A PRIMEIRA INFORMACAO EH A QUANTIDADE DE DADOS ARMAZENADOS!!!
        fread(&lista->n, sizeof(int), 1, arquivo);
        // AGORA VAMOS LER O VETOR INTEIRO!!!
        fread(lista->itens, sizeof(Produto), TOTAL, arquivo);
        fclose(arquivo);
        printf("Base de dados do estoque carregada com sucesso!\n");
    }

    do {
        printf("\n=== Menu do Estoque ===\n");
        printf("1. Produto\n");
        printf("2. Relatorios\n");
        printf("3. Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d%*c", &opcao_principal);

        switch (opcao_principal) {
            case 1:
                do {
                	strcpy(subMenuNome, "Produto");
                	submenu(subMenuNome);
                    scanf("%d%*c", &opcao_submenu);
				    switch (opcao_submenu) {
				        case 1:
				            incluir_produto(lista);
				            break;
				        case 2:
				            alterar_produto(lista);
				            break;
				        case 3:
				            apagar_produto(lista);
				            break;
				        case 4:
				            consultar_produto(lista);
				            break;
				        case 5:
				            consultarTodos_produto(lista);
				            break;
				        case 6:
				            printf("\nVoltando ao menu anterior...\n\n");
				            break;
				        default:
				            printf("Opcao invalida.\n");
				    }
                } while (opcao_submenu != 6);
                break;
            case 2:
            	do { 
				    printf("\n=== Submenu Relatorios ===\n");
				    printf("1. Codigo Ordenado\n");
				    printf("2. Nome Ordenado\n");
				    printf("3. Preco Ordenado\n");
					printf("4. Quantidade Ordenado\n");
					printf("5. Estoque Baixo\n");
					printf("6. Voltar ao menu anterior\n");
				    printf("\nEscolha uma opcao: ");
	                scanf("%d%*c", &opcao_submenu);
				    switch (opcao_submenu) {
				        case 1:
				            ordenarCodigo(lista);
				            consultarTodos_produto(lista);
				            break;
				        case 2:
				            ordenarNome(lista);
				            consultarTodos_produto(lista);
							break;
				        case 3:
				            ordenarPreco(lista);
				            consultarTodos_produto(lista);
							break;
				        case 4:
				            ordenarQuantidade(lista);
				            consultarTodos_produto(lista);
							break;
				        case 5:
				            estoqueBaixo(lista);
				            break;
				        case 6:
				            printf("\nVoltando ao menu anterior...\n\n");
				            break;
				        default:
				            printf("Opcao invalida.\n");
				    }
                } while (opcao_submenu != 6);
                break;
            case 3:
                if (lista->n != 0) 
                {
                    arquivo = fopen("Estoque.dat", "wb");
                    // PRECISA GRAVAR A QUANTIDADE DE DADOS ARMAZENADOS!!!!
                    fwrite(&lista->n, sizeof(int), 1, arquivo);
                    // AGORA GRAVAR O VETOR INTEIRO!!!!
                    fwrite(lista->itens, sizeof(Produto), TOTAL, arquivo);
                    fclose(arquivo);
                }
                printf("Dados Gravados!\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao_principal != 3);
    free(lista);
	printf("\n* Obrigado por usar nosso sistema! *");
}
