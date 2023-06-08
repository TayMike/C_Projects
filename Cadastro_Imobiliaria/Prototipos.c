// Cliente:

int existe_cliente( Cliente *vetClin, int totClin, char cpf[]);

void incluir_cliente( Cliente *vetClin, int *totClin );

void alterar_cliente( Cliente *vetClin, int *totClin );

void apagar_cliente( Cliente *vetClin, int *totClin, Locacao *vetLoc, int totLoc );

void consultar_cliente( Cliente *vetClin, int *totClin );

void consultarTodos_cliente( Cliente *vetClin, int *totClin );

// Imovel:

int existe_imovel( Imovel *vetImovel, int totImovel, char sigla[]);

void incluir_imovel( Imovel *vetImovel, int *totImovel );

void alterar_imovel( Imovel *vetImovel, int *totImovel );

void apagar_imovel( Imovel *vetImovel, int *totImovel, Locacao *vetLoc, int totLoc );

void consultar_imovel( Imovel *vetImovel, int *totImovel );

void consultarTodos_imovel( Imovel *vetImovel, int *totImovel );

// Locacao:

int existe_clin_loc( Locacao *vetLoc, int totLoc, char cpf[] );

int existe_imovel_loc( Locacao *vetLoc, int totLoc, char sigla[] );

int existe_locacao( Locacao *vetLoc, int totLoc, char CPF[], char codigo[], char data[]);

void incluir_locacao( Cliente *vetClin, int totClin, 
                      Imovel *vetImovel, int totImovel, 
                      Locacao *vetLoc, int *totLoc );

void alterar_locacao( Cliente *vetClin, int totClin, 
                      Imovel *vetImovel, int totImovel, 
                      Locacao *vetLoc, int *totLoc );

void apagar_locacao( Locacao *vetLoc, int *totLoc );

void consultar_locacao( Locacao *vetLoc, int *totLoc );

void consultarTodas_locacao( Locacao *vetLoc, int *totLoc );

void locacoes_por_sigla( Cliente *vetClin, int totClin, 
                         Imovel *vetImovel, int totImovel, 
                         Locacao *vetLoc, int totLoc );
                         
void locacoes_entre_anos( Cliente *vetClin, int totClin, 
                          Imovel *vetImovel, int totImovel, 
                          Locacao *vetLoc, int totLoc );
                          
// Relatorio:

void relatorioTipo(Cliente *vetClin, int totClin, Imovel *vetImovel, int totImovel, Locacao *vetLoc, int totLoc);

void relatorioData(Cliente *vetClin, int totClin, Imovel *vetImovel, int totImovel, Locacao *vetLoc, int totLoc);
