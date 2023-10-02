#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _no {
	char comando;
    char elem[30];
    struct _no *prox;
} t_no;

typedef struct {
    t_no *inicio;
    t_no *fim;
    int n;
} t_lista;

t_lista* criarLista() {
    t_lista *lista;
    lista = (t_lista *) malloc(sizeof(t_lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->n = 0;
    return lista;
}

int vazia(t_lista *lista) {
	if (lista->n == 0)
		return 1;
	return 0;
}

int tamanho(t_lista *lista) {
	return lista->n;
}

void RemoveChar(char *s)
{
    int i = 2, j = 0;
    while (s[i] != '\0')
    { 
        s[j] = s[i];
        j++;
        i++;       
    }
    s[j] = s[i];
}

int inserirFimMain(t_lista *lista, char *item) {
    t_no *no;
    no = (t_no *) malloc(sizeof(t_no));
    if (strlen(item) == 1)
    	no->comando = item[0];
    else {
    	no->comando = item[0];
    	RemoveChar(item);
		strcpy(no->elem, item);
    }
    no->prox = NULL;
    if (lista->inicio == NULL) {
        lista->inicio = no;
    } else {
        lista->fim->prox = no;
    }
    lista->fim = no;
    lista->n++;
}

int inserirFim(t_lista *lista, char *item) {
    t_no *no;
    no = (t_no *) malloc(sizeof(t_no));
	strcpy(no->elem, item);
    no->prox = NULL;
    if (lista->inicio == NULL) {
        lista->inicio = no;
    } else {
        lista->fim->prox = no;
    }
    lista->fim = no;
    lista->n++;
}

void imprimirNo(t_no *no) {
    printf("%s", no->elem);
}

void imprimir(t_lista *lista) {
    int qtdePrioridade = 0, chamada = 0;
    char comando;
	t_lista *suporteGeral;
	t_lista *suportePrioridade;
    t_no *no_aux = lista->inicio;
    t_no *no_fila;
    suporteGeral = criarLista();
    suportePrioridade = criarLista();
	while (no_aux->comando != 'f') {
		switch (no_aux->comando){
	    	case 'g':
	    		inserirFim(suporteGeral, no_aux->elem);
	    		break;
			case 'p':
				inserirFim(suportePrioridade, no_aux->elem);
				break;
			case 's':
				if (tamanho(suportePrioridade) > 0 && qtdePrioridade < 3) {
					no_fila = suportePrioridade->inicio;
					printf("%s\n", no_fila->elem);
					remover(suportePrioridade, no_fila->elem); 
					qtdePrioridade++;
				} else {
					if (tamanho(suporteGeral) > 0) {
					no_fila = suporteGeral->inicio;
					printf("%s\n", no_fila->elem);
					remover(suporteGeral, no_fila->elem);
					if (qtdePrioridade == 3) {
						qtdePrioridade = 0;	
					}	
					} else {
						chamada++;
					}
				}
		}
        no_aux = no_aux->prox;
    }
    while (chamada != 0) {
		if (tamanho(suportePrioridade) > 0 && qtdePrioridade < 3) {
			no_fila = suportePrioridade->inicio;
			printf("%s\n", no_fila->elem);
			remover(suportePrioridade, no_fila->elem); 
			qtdePrioridade++;
		} else {
			if (tamanho(suporteGeral) > 0) {
			no_fila = suporteGeral->inicio;
			printf("%s\n", no_fila->elem);
			remover(suporteGeral, no_fila->elem);
			if (qtdePrioridade == 3) {
				qtdePrioridade = 0;
			}
			}
		}
		chamada--;
	}
	free(suporteGeral);
	free(suportePrioridade);
	free(no_fila);
    printf("\n");
}

void limpar(t_lista *lista) {
	t_no *no_aux = lista->inicio;
	t_no *free_aux;
    while (no_aux != NULL) {
		free_aux = no_aux;
        no_aux = no_aux->prox;
    	free(free_aux);
	}
	lista->inicio = NULL;
	lista->fim = NULL;
	lista->n = 0;
}

void liberarLista(t_lista *lista) {
	free(lista);
}

int remover(t_lista *lista, char *item) {
    t_no *no_aux;
    t_no *no_ant;
    no_aux = lista->inicio;
    no_ant = no_aux;
    while (no_aux != NULL) {
        if (no_aux->elem == item) {
            if (no_aux == lista->inicio) {
                lista->inicio = lista->inicio->prox;
            } else {
                no_ant->prox = no_aux->prox;
                if (no_aux == lista->fim) {
                    lista->fim = no_ant;
                }
            }
            free(no_aux);
            lista->n--;
            return 1;
        }
        no_ant = no_aux;
        no_aux = no_aux->prox;
    }
    return 0;
}

int main() {
    t_lista *lista;
    t_no *no;
    char palavra[30];

    lista = criarLista();

	printf("Digite o proximo comando: \n");
	gets(palavra);
	inserirFimMain(lista, palavra);
	while (palavra[0] != 'f') {
		printf("Digite o proximo comando: \n");
		gets(palavra);
    	inserirFimMain(lista, palavra);
    }
    
    imprimir(lista);
    limpar(lista);
	liberarLista(lista);

    return 1;
}
