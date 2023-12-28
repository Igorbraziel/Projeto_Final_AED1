#include "estruturas.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

// Funções adicionais //===================================================================================
void CopiaString(char * original, char * copia){
    int i = 0;

    while(original[i] != '\0' && i < TAM_MAX){
        copia[i] = original[i];
        i++;
    }

}

void LeString(char * string){
    char c = 'a';
    int i = 0;

    while(true){
        if(i == TAM_MAX) break;
        scanf("%c", &c);
        if(c == '\n') break;
        string[i] = c;
        i++;
    }

    string[i] = '\0';
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

Produto * CriarProduto(int codigo, int quantidade, char * nome){
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
        if(atual->codigo >= prod->codigo){
            prod->proximo = atual;
            atual->anterior = prod;
            est->primeiro = prod;
            (est->tamanho)++;
            return SUCESSO;
        }
        while(true){
            if(atual->codigo >= prod->codigo){
                break;
            }
            if(atual->proximo == NULL){
                atual->proximo = prod;
                prod->anterior = atual;
                (est->tamanho)++;
                return SUCESSO;
            }
            atual = atual->proximo;
        }
        Produto * anterior = atual->anterior;
        anterior->proximo = prod;
        prod->anterior = anterior;
        atual->anterior = prod;
        prod->proximo = atual;
        (est->tamanho)++;
        return SUCESSO;
    }

    return FALHA;
}

void MostrarProduto(Produto * p){
    if(p == NULL) return;

    std::cout << "Codigo do produto: " << p->codigo << std::endl;
    std::cout << "Quantidade do produto no estoque: " << p->quantidade << std::endl;
    std::cout << "Nome do produto: " << p->nome << std::endl;
    std::cout << "=================================================================" << std::endl;
}

void MostrarEstoque(Estoque * est){
    if(est == NULL) return;

    Produto * atual = est->primeiro;
    while(atual != NULL){
        MostrarProduto(atual);
        atual = atual->proximo;
    }
}

Produto * MaquinaProdutos(){
    int codigo, quantidade;
    char nome[TAM_MAX];
    Produto * p = NULL;
    std::cout << "Digite um codigo para seu produto: ";
    std::cin >> codigo;
    std::cout << "Digite a quantidade deste produto: ";
    scanf("%d%*c", &quantidade);
    std::cout << "Digite um nome para seu produto: ";
    LeString(nome);
    p = CriarProduto(codigo, quantidade, nome);
    return p;
}

bool AdicionarPedido(Fila * f, Pedido * ped);
bool RemoverPedido(Fila * f, Pedido * ped);

bool RemoverEstoque(Estoque * est, Produto * prod){
    if(est == NULL || prod == NULL) return FALHA;
    Produto * atual = est->primeiro;
    if(atual == NULL) return FALHA;
    if(atual->codigo == prod->codigo){
        est->primeiro = est->primeiro->proximo;
        free(atual);
        (est->tamanho)--;
        return SUCESSO;
    } else{
        while(true){
            if(atual->codigo == prod->codigo){
                if(atual->proximo == NULL){
                    atual->anterior->proximo = NULL;
                    free(atual);
                    (est->tamanho)--;
                    return SUCESSO;
                } else{
                    Produto * anterior = atual->anterior;
                    Produto * posterior = atual->proximo;
                    anterior->proximo = posterior;
                    posterior->anterior = anterior;
                    free(atual);
                    (est->tamanho)--;
                    return SUCESSO;
                }
            }
            if(atual->proximo == NULL) break;
            atual = atual->proximo;
        }
    }

    return FALHA;
}

bool AtendePedido(Estoque * est, Fila * f, Pedido * ped){
    if(est == NULL || ped == NULL) return FALHA;
    Produto * atual = est->primeiro;
    if(atual == NULL) return FALHA;
    while(true){
        if(atual->codigo == ped->numero){
            if(atual->quantidade >= ped->quantidade_pedidos){
                atual->quantidade -= ped->quantidade_pedidos;
                RemoverPedido(f, ped);
                if(atual->quantidade == 0) RemoverEstoque(est, atual);
                return SUCESSO;
            } else return FALHA;
         }
         if(atual->proximo == NULL) break;
         atual = atual->proximo;
    }

    return FALHA;
}



//===================================================================================