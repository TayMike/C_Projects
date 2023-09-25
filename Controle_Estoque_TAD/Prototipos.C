// Lista

t_lista* criarLista(int tam);

int cheia(t_lista *lista);

int vazia(t_lista *lista);

int tamanho(t_lista *lista);

int inserirFim(t_lista *lista, Produto elem);

int inserirIndice(t_lista *lista, int indice, Produto elem);

Produto consultarProduto(t_lista *lista, char codigo[]);

int consultarProdutoIndice(t_lista *lista, char codigo[]);

int atualizarProduto(t_lista *lista, Produto elem);

int removerIndice(t_lista *lista, int indice);

int removerFim(t_lista *lista);

int limparTudo(t_lista *lista);

// Estoque:

void exibirProduto(Produto produto);

void incluir_produto(t_lista *lista);

void alterar_produto(t_lista *lista);

void apagar_produto(t_lista *lista);

void consultar_produto(t_lista *lista);

void consultarTodos_produto(t_lista *lista);

// Relatorio:

void ordenarCodigo(t_lista *lista);

void ordenarNome(t_lista *lista);

void ordenarPreco(t_lista *lista);

void ordenarQuantidade(t_lista *lista);

void estoqueBaixo(t_lista *lista);
