#include<stdio.h>
#include<stdlib.h>
#include<string.h>

t_lista* criarLista(int tam) {
    t_lista *lista = (t_lista *) malloc(sizeof(t_lista));
    lista->max = tam;
    lista->n = 0;
    lista->itens = (Produto *) malloc(sizeof(Produto) * tam);
    return lista;
}

int cheia(t_lista *lista) {
    //return lista->n == lista->max;
    if (lista->n == lista->max) {
        return 1;
    }
    return 0;
}

int vazia(t_lista *lista) {
    if (lista->n == 0) {
        return 1;
    }
    return 0;
}

int tamanho(t_lista *lista) {
    return lista->n;
}

int inserirFim(t_lista *lista, Produto elem) {
    if (!cheia(lista)) {
        lista->itens[lista->n] = elem;
        lista->n++;
        return 1;
    }
    return 0;
}

int inserirIndice(t_lista *lista, int indice, Produto elem) {
    if (!cheia(lista) && (indice < lista->n)) {
        for (int i = lista->n - 1; i >= indice; i--) {
            lista->itens[i + 1] = lista->itens[i];
        }
        lista->itens[indice] = elem;
        lista->n++;
        (*lista).n;
        return 1;
    }
    return 0;
}

Produto consultarProduto(t_lista *lista, char codigo[]) {
	Produto produto;
	if (!vazia(lista)) {
        for (int i = 0; i < lista->n; i++) {
            if(strcmp(lista->itens[i].codigo, codigo) == 0)
            	return lista->itens[i];
        }
    }
    produto.flag = 0;
    return produto;
}

int consultarProdutoIndice(t_lista *lista, char codigo[]) {
    if (!vazia(lista)) {
        for (int i = lista->n - 1; i >= 0; i--) {
            if(strcmp(lista->itens[i].codigo, codigo) == 0) 
            	return i;
        }
    }
    return -1;
}

int atualizarProduto(t_lista *lista, Produto elem) {
    if (!vazia(lista)) {
        for (int i = lista->n - 1; i >= 0; i--) {
            if(strcmp(lista->itens[i].codigo, elem.codigo) == 0) {
            	lista->itens[i] = elem;
				return 1;
			}
        }
    }
    return 0;
}

int removerIndice(t_lista *lista, int indice) {
    if (!vazia(lista) && (indice < lista->n)) {
        for (int i = indice; i < lista->n - 1; i++) {
            lista->itens[i] = lista->itens[i + 1];
        }
        lista->n--;
        (*lista).n;
        return 1;
    }
    return 0;
}

int removerFim(t_lista *lista) {
    if (!vazia(lista)) {
        lista->n--;
        return 1;
    }
    return 0;
}

int limparTudo(t_lista *lista) {
    lista->n = 0;
    return 1;
}
