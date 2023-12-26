#include "estruturas.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

// Funções adicionais //===================================================================================
void CopiaString(char * original, char * copia){
    int i;

    while(original[i] != '\0' && i < TAM_MAX){
        copia[i] = original[i];
        i++;
    }
}
//===================================================================================

// Criação //===================================================================================
Estoque * CriarEstoque(){
    Estoque * est = NULL;
    est = (Estoque *) malloc(1 * sizeof(Estoque));
    est->tamanho = 0;
    est->primeiro = NULL;

    return est;
}

Fila * CriarFila(){
    Fila * f = NULL;
    f = (Fila *) malloc(1 * sizeof(Fila));
    f->tamanho = 0;
    f->primeiro = NULL;

    return f;
}

Pilha * CriarPilha(){
    Pilha * p = NULL;
    p = (Pilha *) malloc(1 * sizeof(Pilha));
    p->tamanho = 0;
    p->ultimo = NULL;

    return p;
}

Produto * CriarProduto(int codigo, int quantidade, char nome[TAM_MAX]){
    Produto * prod = NULL;
    prod = (Produto *) malloc(1 * sizeof(Produto));
    prod->codigo = codigo;
    prod->quantidade = quantidade;
    CopiaString(nome, prod->nome);
    prod->anterior = NULL;
    prod->proximo = NULL;

    return prod;
}

Pedido * CriarPedido(int numero, int quantidade_pedidos){
    Pedido * ped = NULL;
    ped = (Pedido *) malloc(1 * sizeof(Pedido));
    ped->numero = numero;
    ped->quantidade_pedidos = quantidade_pedidos;
    ped->anterior = NULL;
    ped->proximo = NULL;

    return ped;
}
//===================================================================================

// Destruição //=====================================================================

void DestruirEstoque(Estoque * est){
    if(est == NULL) return;
    Produto * primeiro = est->primeiro;
    Produto * anterior = NULL;
    while(primeiro != NULL){
        anterior = primeiro;
        primeiro = primeiro->proximo;
        free(anterior);
    }

    free(est);
}

void DestruirFila(Fila * f){
    if(f == NULL) return;
    Pedido * primeiro = f->primeiro;
    Pedido * anterior = NULL;
    while(primeiro != NULL){
        anterior = primeiro;
        primeiro = primeiro->proximo;
        free(anterior);
    }

    free(f);
}

void DestruirPilha(Pilha * p){
    if(p == NULL) return;
    Produto * ultimo = p->ultimo;
    Produto * posterior = NULL;
    while(ultimo != NULL){
        posterior = ultimo;
        ultimo = ultimo->anterior;
        free(posterior);
    }

    free(p);
}

void DestruirProduto(Produto * prod){
    if(prod == NULL) return;
    free(prod);
}

void DestruirPedido(Pedido * ped){
    if(ped == NULL) return;
    free(ped);
}

//===================================================================================

// Funções para adição, remoção, em estruturas, etc. // =============================

bool AdicionarEstoque(Estoque * est, Produto * prod){
    if(est == NULL || prod == NULL) return FALHA;

    if(est->primeiro == NULL){
        est->primeiro = prod;
        (est->tamanho)++;
        return SUCESSO;
    } else{
        Produto * atual = est->primeiro;
        while(true){
            if(atual->proximo->codigo >= prod->codigo){
                break;
            }
            atual = atual->proximo;
            if(atual->proximo == NULL){
                atual->proximo = prod;
                prod->anterior = atual;
                (est->tamanho)++;
                return SUCESSO;
            }
        }
        Produto * posterior = atual->proximo;
        atual->proximo = prod;
        prod->anterior = atual;
        prod->proximo = posterior;
        posterior->anterior = prod;
        (est->tamanho)++;
        return SUCESSO;
    }

    return FALHA;
}

//===================================================================================