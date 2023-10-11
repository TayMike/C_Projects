#include<stdio.h>
#include<stdlib.h>

typedef int t_elem;

typedef struct {
    int max;
    int inicio;
    int fim;
    t_elem *itens;
} t_fila;

t_fila* create(int n) {
    t_fila *f = (t_fila *) malloc(sizeof(t_fila));
    f->max = n;
    f->itens = (t_elem *) malloc(sizeof(t_elem) * n);
    f->inicio = 0;
    f->fim = 0;
    return f;
}

void enqueue(t_fila *f, t_elem x) {
    f->itens[f->fim] = x;
    f->fim = (f->fim + 1) % f->max;
}

int dequeue(t_fila *f, t_elem *x) {
    if (!isEmpty(f)) {
        *x = f->itens[f->inicio];
        f->inicio = (f->inicio + 1) % f->max;
        return 1;
    }
    return 0;
}

int front(t_fila *f) {
	if (!isEmpty(f)) {
        return f->itens[f->inicio];
    }
}

int size(t_fila *f) {
	int i = 0;
	if (isEmpty(f)) {
        return 0;
    } else {
    	return f->fim + 1;
	}
}

int isEmpty(t_fila *f) {
    return f->inicio == f->fim;
}

int clear(t_fila *f) {
    f->inicio = 0;
    f->fim = 0;
    return 1;
}

void destroy(t_fila *f) {
    free(f->itens);
    free(f);
}

void print(t_fila *f) {
    int i = 0;
    for (i = f->inicio; i != f->fim; i = (i + 1) % f->max) {
        printf("%d\t", f->itens[i]);
    }
    printf("\n");
}

int main() {
    int n = 3;
    int x;

    t_fila *fila;

    fila = create(n);

    enqueue(fila, 151);
    enqueue(fila, 152);
    print(fila);
    dequeue(fila, &x);
    enqueue(fila, 153);
    print(fila);
    dequeue(fila, &x);
    enqueue(fila, 154);
    print(fila);
    printf("%d\n", front(fila));
    printf("%d\n", size(fila));
    printf("%d\n", clear(fila));

    destroy(fila);

    return 1;
}

