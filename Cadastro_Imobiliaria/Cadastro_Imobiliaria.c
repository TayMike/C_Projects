#include <stdio.h>
#include "Estruturas.c"
#include "Prototipos.c"
#include "Clientes.c"
#include "Imovel.c"
#include "Locacao.c"
#include "Relatorios.c"

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
    // Criando os armazenamentos:
    Cliente BDclientes[TOTAL];
        // Variavel que vai indicar quantos clientes estao cadastrados no vetor:
        int totClin = 0;
        
    Imovel BDimovel[TOTAL];
        // Variavel que vai indicar quantos imoveis estao cadastrados no vetor:
        int totImovel = 0;
        
    Locacao BDlocacao[TOTAL];
        // Variavel que vai indicar quantas locacoes estao cadastrados no vetor:
        int totLoc = 0;
    
    // Menus de opcoes:
    int opcao_principal, opcao_submenu;
    
    char subMenuNome[15];
    
	// Carregando arquivo, caso exista:
    FILE *arquivo;
    arquivo = fopen("BDclientes.dat", "rb");
    if(arquivo != NULL)
    {
        // A PRIMEIRA INFORMACAO EH A QUANTIDADE DE DADOS ARMAZENADOS!!!
        fread(&totClin, sizeof(int), 1, arquivo);
        // AGORA VAMOS LER O VETOR INTEIRO!!!
        fread(BDclientes, sizeof(Cliente), TOTAL, arquivo);
        fclose(arquivo);
        printf("Base de dados dos clientes carregada com sucesso!\n");
    }
    arquivo = fopen("BDimovel.dat", "rb");
    if(arquivo != NULL)
    {
        fread(&totImovel, sizeof(int), 1, arquivo);
        fread(BDimovel, sizeof(Imovel), TOTAL, arquivo);
        fclose(arquivo);
        printf("Base de dados dos imoveis carregada com sucesso!\n");
    }
    arquivo = fopen("BDlocacao.dat", "rb");
    if(arquivo != NULL)
    {
        fread(&totLoc, sizeof(int), 1, arquivo);
        fread(BDlocacao, sizeof(Locacao), TOTAL, arquivo);
        fclose(arquivo);
        printf("Base de dados das locacoes carregada com sucesso!\n");
    }

    do {
        printf("\n=== Menu ===\n");
        printf("1. Cliente\n");
        printf("2. Imovel\n");
        printf("3. Locacao\n");
        printf("4. Relatorios\n");
        printf("5. Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d%*c", &opcao_principal);

        switch (opcao_principal) {
            case 1:
                do {
                	strcpy(subMenuNome, "Cliente");
                	submenu(subMenuNome);
                    scanf("%d%*c", &opcao_submenu);
				    switch (opcao_submenu) {
				        case 1:
				            incluir_cliente(BDclientes, &totClin);
				            break;
				        case 2:
				            alterar_cliente(BDclientes, &totClin);
				            break;
				        case 3:
				            apagar_cliente(BDclientes, &totClin, BDlocacao, totLoc);
				            break;
				        case 4:
				            consultar_cliente(BDclientes, &totClin);
				            break;
				        case 5:
				            consultarTodos_cliente(BDclientes, &totClin);
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
                	strcpy(subMenuNome, "Imovel");
                	submenu(subMenuNome);
                    scanf("%d%*c", &opcao_submenu);
				    switch (opcao_submenu) {
				        case 1:
				            incluir_imovel(BDimovel, &totImovel);
				            break;
				        case 2:
				            alterar_imovel(BDimovel, &totImovel);
				            break;
				        case 3:
				            apagar_imovel(BDimovel, &totImovel, BDlocacao, totLoc);
				            break;
				        case 4:
				            consultar_imovel(BDimovel, &totImovel);
				            break;
				        case 5:
				            consultarTodos_imovel(BDimovel, &totImovel);
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
               do {
               		strcpy(subMenuNome, "Locacao");
               		submenu(subMenuNome);
                    scanf("%d%*c", &opcao_submenu);
				    switch (opcao_submenu) {
				        case 1:
				            incluir_locacao(BDclientes, totClin, BDimovel, totImovel, BDlocacao, &totLoc);
				            break;
				        case 2:
				            alterar_locacao(BDclientes, totClin, BDimovel, totImovel, BDlocacao, &totLoc);
				            break;
				        case 3:
				            apagar_locacao(BDlocacao, &totLoc);
				            break;
				        case 4:
				            consultar_locacao(BDlocacao, &totLoc);
				            break;
				        case 5:
				            consultarTodos_locacao(BDlocacao, &totLoc);
				        case 6:
				            printf("\nVoltando ao menu anterior...\n\n");
				            break;
				        default:
				            printf("Opcao invalida.\n");
				    }
                } while (opcao_submenu != 6);
                break;
            case 4:
            	do { 
				    printf("\n=== Submenu Relatorios ===\n");
				    printf("1. Relatorio 1\n");
				    printf("2. Relatorio 2\n");
				    printf("3. Voltar ao menu anterior\n");
				    printf("\nEscolha uma opcao: ");
	                scanf("%d%*c", &opcao_submenu);
				    switch (opcao_submenu) {
				        case 1:
				            relatorioTipo(BDclientes, totClin, BDimovel, totImovel, BDlocacao, totLoc);
				            break;
				        case 2:
				            relatorioData(BDclientes, totClin, BDimovel, totImovel, BDlocacao, totLoc);
				            break;
				        case 3:
				            printf("\nVoltando ao menu anterior...\n\n");
				            break;
				        default:
				            printf("Opcao invalida.\n");
				    }
                } while (opcao_submenu != 3);
                break;
            case 5:
                if (totClin != 0) 
                {
                    arquivo = fopen("BDclientes.dat", "wb");
                    // PRECISA GRAVAR A QUANTIDADE DE DADOS ARMAZENADOS!!!!
                    fwrite(&totClin, sizeof(int), 1, arquivo);
                    // AGORA GRAVAR O VETOR INTEIRO!!!!
                    fwrite(BDclientes, sizeof(Cliente), TOTAL, arquivo);
                    fclose(arquivo);
                }
                if (totImovel != 0) 
                {
                    arquivo = fopen("BDimovel.dat", "wb");
                    fwrite(&totImovel, sizeof(int), 1, arquivo);
                    fwrite(BDimovel, sizeof(Imovel), TOTAL, arquivo);
                    fclose(arquivo);
                }
                if (totLoc != 0) 
                {
                    arquivo = fopen("BDlocacao.dat", "wb");
                    fwrite(&totLoc, sizeof(int), 1, arquivo);
                    fwrite(BDlocacao, sizeof(Locacao), TOTAL, arquivo);
                    fclose(arquivo);
                }
                printf("Dados Gravados!\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao_principal != 5);
	printf("\n* Obrigado por usar nosso sistema! *");
}

