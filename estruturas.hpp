#ifndef __ESTRUTURAS_HPP__
#define __ESTRUTURAS_HPP__

#define TAM_MAX 100

struct produto{
    int codigo;
    int quantidade;
    char nome[TAM_MAX];
    struct produto * proximo;
    struct produto * anterior;
};

typedef struct produto Produto;

struct estoque{
    int quantidade_produtos;
    Produto * primeiro;
};

typedef struct estoque Estoque;

struct pedido{
    int numero;
    int quantidade_pedidos;
    struct pedido * proximo;
    struct pedido * anterior;
};

typedef struct pedido Pedido;

struct fila{
    int quantidade_pedidos;
    Pedido * primeiro;
};

typedef struct fila Fila;

struct pilha{
    Produto * ultimo;
    int tamanho;
};

typedef struct pilha Pilha;

#endif