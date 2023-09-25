#include <stdio.h>
#include <stdlib.h>

// Criando constante que representa a capacidade maxima dos vetores:
#define TOTAL 3

// Definindo a estrutura Produto:

typedef struct {
    
    char nome[31];
    char codigo[15];
    int quantidade;
    double preco;
    bool flag;
    
} Produto;

// Definindo a estrutura Lista:

typedef struct {
    int max;
    int n;
    Produto *itens;
} t_lista;
