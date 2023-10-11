#include<stdio.h>
#include<stdlib.h>

typedef int t_elem;

typedef struct {
    int max;
    int topo;
    t_elem *itens;
} t_pilha;

t_pilha* create(int n) {
    t_pilha *p = (t_pilha *) malloc(sizeof(t_pilha));
    p->max = n;
    p->itens = (t_elem *) malloc(sizeof(t_elem) * n);
    p->topo = -1;
    return p;
}

int isFull(t_pilha *p) {
    return p->topo >= p->max - 1;
}

int push(t_pilha *p, t_elem x) {
    if (!isFull(p)) {
        p->topo++;
        p->itens[p->topo] = x;
        return 1;
    }
    return 0;
}

int pop(t_pilha *p, t_elem *x) {
    if (!isEmpty(p)) {
        *x = p->itens[p->topo];
        p->topo--;
        return 1;
    }
    return 0;
}

int top(t_pilha *p, t_elem *x) {
    if (!isEmpty(p)) {
        *x = p->itens[p->topo];
        return 1;
    }
    return 0;
}

int size(t_pilha *p) {
    return p->topo + 1;	
}

int isEmpty(t_pilha *p) {
    if (p->topo < 0) {
        return 1;
    }
    return 0;
}

int clear(t_pilha *p) {
    p->topo = -1;
    return 1;
}

void destroy(t_pilha *p) {
    free(p->itens);
    free(p);
}

void print(t_pilha *p) {
    int i = 0;
    for (i = 0; i <= p->topo; i++) {
        printf("%d\t", p->itens[i]);
    }
    printf("\n");
}

int main() {

    t_pilha *pilha;

    pilha = create(3);

    push(pilha, 151);
    push(pilha, 158);
    push(pilha, 7);
    push(pilha, 70);
    
    t_elem x = 0;
    pop(pilha, &x);
    printf("%d\n", x);
    top(pilha, &x);
	printf("%d\n", x);
	printf("%d\n", size(pilha));
	printf("%d\n", isEmpty(pilha));
    print(pilha);
    printf("%d\n", clear(pilha));
    destroy(pilha);

    return 1;
}
