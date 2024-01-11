#ifndef __ESTRUTURAS_HPP__
#define __ESTRUTURAS_HPP__

#define TAM_MAX 100 + 1

#define SUCESSO true
#define FALHA false

//cores //==============================================

#define LIMPA "\033[0m"
#define LIMPA_FUNDO "\033[49m"

#define BRANCO "\033[1;30m"
#define VERMELHO "\033[1;31m"
#define VERDE "\033[1;32m"
#define AMARELO "\033[1;33m"
#define AZUL "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CIANO "\033[1;36m"
#define CINZA "\033[1;37m"

#define FUNDO_BRANCO "\033[1;40m"
#define FUNDO_VERMELHO "\033[1;41m"
#define FUNDO_VERDE "\033[1;42m"
#define FUNDO_AMARELO "\033[1;43m"
#define FUNDO_AZUL "\033[1;44m"
#define FUNDO_MAGENTA "\033[1;45m"
#define FUNDO_CIANO "\033[1;46m"
#define FUNDO_CINZA "\033[1;47m"

//======================================================

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
    char nome[TAM_MAX]; // numero referente ao código do produto que vai ser pedido
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
Pedido * CriarPedido(char * nome, int quantidade_pedidos);

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

void IntroducaoEstoque(int tam, const char borda);
void IntroducaoFila(int tam, const char borda);
void IntroducaoPilha(int tam, const char borda);

void LinhaVerde();

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
Pedido * MaquinaPedidos();

//Funções adicionais //============================================================================

void LeString(char * string);

//=================================================================================================


#endif
