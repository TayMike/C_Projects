#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Criando constante que representa a capacidade maxima dos vetores:
#define TOTAL 50

// Definindo a estrutura Cliente:

typedef struct {
    
    char CPF[12];
    char nome[31];
    float salario;
    char email[31];
    
} Cliente;

// Definindo a estrutura Imovel:

typedef struct {
    
    char codigo[12];
    char descricao[31];
    char endereco[31];
    char tipo[12];
    
} Imovel;

// Definindo a estrutura Locacao:

typedef struct {
    
    char CPF[12];
    char codigo[12];
    char data[11];
    float aluguel;
    
} Locacao;

struct tm parse_date(char *str) 
{
    struct tm tm = {0};
    char *token;

    // Extrai o dia, mês e ano usando a função strtok
    token = strtok(str, "/");
    tm.tm_mday = atoi(token);
    token = strtok(NULL, "/");
    tm.tm_mon = atoi(token) - 1;
    token = strtok(NULL, "/");
    tm.tm_year = atoi(token) - 1900;

    return tm;
}
