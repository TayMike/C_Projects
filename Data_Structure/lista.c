#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int max;
    int n;
    int *itens;
} t_lista;

t_lista* criarLista(int tam) {
    t_lista *lista = (t_lista *) malloc(sizeof(t_lista));
    lista->max = tam;
    lista->n = 0;
    lista->itens = (int *) malloc(sizeof(int) * tam);
    return lista;
}

int isFull(t_lista *lista) {
    if (lista->n == lista->max) {
        return 1;
    }
    return 0;
}

int append(t_lista *lista, int elem) {
    if (!isFull(lista)) {
        lista->itens[lista->n] = elem;
        lista->n++;
        return 1;
    }
    return 0;
}

int insert(t_lista *lista, int index, int elem) {
	int i =  lista->n - 1;
    if (!isFull(lista) && (index < lista->n)) {
        for (i; i >= index; i--) {
            lista->itens[i + 1] = lista->itens[i];
        }
        lista->itens[index] = elem;
        lista->n++;
        return 1;
    }
    return 0;
}

int update(t_lista *lista, int index, int elem) {
    if (!isEmpty(lista) && index > -1 && index < lista->n) {
        lista->itens[index] = elem;
        return 1;
    }
    return 0;
}

int removeByIndex(t_lista *lista, int index) {
	int i = index;
    if (!isEmpty(lista) && index > -1 && index < lista->n) {
        for (i; i < lista->n - 1; i++) {
            lista->itens[i] = lista->itens[i + 1];
        }
        lista->n--;
        return 1;
    }
    return 0;
}

int removeByElement(t_lista *lista, int elem) {
	int i = 0;
    if (!isEmpty(lista)) {
		for (i; i < lista->n; i++) {
	        if (lista->itens[i] == elem) {
	        	int j = i;
		        for (j; j < lista->n - 1; j++) {
		            lista->itens[j] = lista->itens[j + 1];
		        }
			    lista->n--;
			    return 1;
		    }
	    }   
	}
    return 0;
}

int indexOf(t_lista *lista, int elem) {
	int i = 0;
	if (!isEmpty(lista)) {
	    for (i; i < lista->n; i++) {
	        if (lista->itens[i] == elem) {
			    return i;
		    }
	    }
	}
	return -1;
}

int get(t_lista *lista, int index) {
    if (!isEmpty(lista) && index > -1 && index < lista->n) {
		return lista->itens[index];
    }
	return -1;
}

int count(t_lista *lista, int elem) {
	int i = 0, j = 0;
	if (!isEmpty(lista)) {
	    for (i; i < lista->n; i++) {
	        if (lista->itens[i] == elem)
			    j++;
	    }
	}
	return j;
}

int size(t_lista *lista) {
    return lista->n;
}

int isEmpty(t_lista *lista) {
    if (lista->n == 0) {
        return 1;
    }
    return 0;
}

int clear(t_lista *lista) {
	lista->n = 0;
	return 1;
}

void destroy(t_lista *lista) {
	free(lista->itens);
	free(lista);
}

void printTest(t_lista *lista) {
	int i = 0;
    for (i; i < size(lista); i++) {
    	printf ("%d\t", lista->itens[i]);
	}
	printf ("\n");
}

int main(int argc, char const *argv[]) {

    t_lista *lista;
    t_lista *listaTeste;

    lista = criarLista(5);
    listaTeste = criarLista(1);

    append(lista, 5);
    append(lista, 3);
    append(lista, 8);
    printTest(lista);
    
    insert(lista, 0, 2);
    printTest(lista);
    
    update(lista, 1, 3);
    printTest(lista);

	removeByIndex(lista, 0);
	printTest(lista);

	printf("%d\n", removeByIndex(lista, 10));
	printf("%d\n", removeByIndex(lista, -2));
	printf("%d\n", removeByIndex(listaTeste, 0));
	
	printf("%d\n", removeByElement(lista, 8));
	printTest(lista);
	
	printf("%d\n", removeByElement(lista, 3));
	printTest(lista);
	
	printf("%d\n", indexOf(lista, 3));
	
	printf("%d\n", get(lista, 3));
	printf("%d\n", get(lista, 0));
	
	append(lista, 3);
	append(lista, 2);
	printf("%d\n", count(lista, 3));
	printf("%d\n", size(lista));
	
	printTest(lista);
	
	clear(lista);
	
	printTest(lista);
	
	destroy(lista);

    return 1;
}
