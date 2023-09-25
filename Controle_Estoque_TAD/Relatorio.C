#include <stdio.h>
#include <stdlib.h>

void ordenarCodigo(t_lista *lista){
	for (int i = 0; i < lista->n - 1; i++) {
	    bool flag = false;
	    for (int j = 0; j < lista->n - i - 1; j++) {
	      if (strcmp(lista->itens[j].codigo, lista->itens[j + 1].codigo) > 0) {
	        Produto temp = lista->itens[j];
	        lista->itens[j] = lista->itens[j + 1];
	        lista->itens[j + 1] = temp;
	        flag = true;
	      }
	    }
	    if (flag == false) break;
    } 
}

void ordenarNome(t_lista *lista){
	for (int i = 0; i < lista->n - 1; i++) {
	    bool flag = false;
	    for (int j = 0; j < lista->n - i - 1; j++) {
	      if (strcmp(lista->itens[j].nome, lista->itens[j + 1].nome) > 0) {
	        Produto temp = lista->itens[j];
	        lista->itens[j] = lista->itens[j + 1];
	        lista->itens[j + 1] = temp;
	        flag = true;
	      }
	    }
	    if (flag == false) break;
    }	
}

void ordenarPreco(t_lista *lista){
	for (int i = 0; i < lista->n - 1; i++) {
	    bool flag = false;
	    for (int j = 0; j < lista->n - i - 1; j++) {
	      if (lista->itens[j].preco > lista->itens[j + 1].preco) {
	        Produto temp = lista->itens[j];
	        lista->itens[j] = lista->itens[j + 1];
	        lista->itens[j + 1] = temp;
	        flag = true;
	      }
	    }
	    if (flag == false) break;
    }		
}

void ordenarQuantidade(t_lista *lista){
	for (int i = 0; i < lista->n - 1; i++) {
	    bool flag = false;
	    for (int j = 0; j < lista->n - i - 1; j++) {
	      if (lista->itens[j].quantidade > lista->itens[j + 1].quantidade) {
	        Produto temp = lista->itens[j];
	        lista->itens[j] = lista->itens[j + 1];
	        lista->itens[j + 1] = temp;
	        flag = true;
	      }
	    }
	    if (flag == false) break;
    }			
}

void estoqueBaixo(t_lista *lista){
	int quantidade;
	int j = 1;
	printf("\nMostrar produtos com o estoque abaixo de qual quantidade?\n");
	scanf("%d", &quantidade);
	for (int i = 0; i < lista->n; i++) {
		if(lista->itens[i].quantidade < quantidade) {
			printf("\n-----%d-----\n", j++);
			exibirProduto(lista->itens[i]);	
		}
	}
	if (j == 1){
		printf("Nenhum produto atende os requisitos!");
	}
}
