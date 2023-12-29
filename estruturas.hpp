#ifndef __ESTRUTURAS_HPP__
#define __ESTRUTURAS_HPP__

#define TAM_MAX 100 + 1

#define SUCESSO true
#define FALHA false


// Estruturas //===================================================================================

struct produto{
    int codigo;
    int quantidade;
    char nome[TAM_MAX];
    struct produto * proximo;
    struct produto * anterior;
};

typedef struct produto Produto;

struct estoque{
    int tamanho;
    Produto * primeiro;
};

typedef struct estoque Estoque;

struct pedido{
    int numero; // numero referente ao código do produto que vai ser pedido
    int quantidade_pedidos; // quantidade solicitada daquele tipo de produto referente ao número
    struct pedido * proximo;
    struct pedido * anterior;
};

typedef struct pedido Pedido;

struct fila{
    int tamanho;
    Pedido * primeiro;
};

typedef struct fila Fila;

struct pilha{
    Produto * ultimo;
    int tamanho;
};

typedef struct pilha Pilha;

// Criação //======================================================================================

Estoque * CriarEstoque();
Fila * CriarFila();
Pilha * CriarPilha();
Produto * CriarProduto(int codigo, int quantidade, char * nome);
Pedido * CriarPedido(int numero, int quantidade_pedidos);

// Destruição //===================================================================================

void DestruirEstoque(Estoque * est);
void DestruirFila(Fila * f);
void DestruirPilha(Pilha * p);
void DestruirProduto(Produto * prod);
void DestruirPedido(Pedido * ped);

// Funções para adição, remoção, em estruturas, etc. // ===========================================

void MostrarProduto(Produto * p);
void MostrarEstoque(Estoque * est);

void MostrarPedido(Pedido * ped);
void MostrarFila(Fila * f);

void MostrarPilha(Pilha * pi);

bool AdicionarEstoque(Estoque * est, Produto * prod);
bool RemoverEstoque(Estoque * est, Produto * prod);

bool AtendePedidoFila(Estoque * est, Fila * f);
bool AdicionarPedidoFinal(Fila * f, Pedido * ped);
bool RemoverPedidoInicio(Fila * f);

bool AdicionarProdutoPilha(Pilha * pi, Produto * prod);
bool RemoverProdutoPilha(Pilha * pi);
bool ReabastecerEstoque(Estoque * est, Pilha * pi);

Produto * MaquinaProdutos();

//Funções adicionais //============================================================================

void CopiaString(char * original, char * copia);
void LeString(char * string);

//=================================================================================================


#endif