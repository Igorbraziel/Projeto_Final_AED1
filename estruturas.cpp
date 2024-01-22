#include "estruturas.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

// Funções adicionais //===================================================================================

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

Produto * CriarProduto(int codigo, int quantidade, char * nome, float preco){
    Produto * prod = NULL;
    prod = (Produto *) malloc(1 * sizeof(Produto));
    prod->codigo = codigo;
    prod->quantidade = quantidade;
    prod->preco = preco;
    strcpy(prod->nome, nome);
    prod->anterior = NULL;
    prod->proximo = NULL;

    return prod;
}

Pedido * CriarPedido(char * nome, int quantidade_pedidos){
    Pedido * ped = NULL;
    ped = (Pedido *) malloc(1 * sizeof(Pedido));
    strcpy(ped->nome, nome);
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
        if(strcmp(atual->nome, prod->nome) > 0){
            prod->proximo = atual;
            atual->anterior = prod;
            est->primeiro = prod;
            (est->tamanho)++;
            return SUCESSO;
        }
        while(true){
            if(strcmp(atual->nome, prod->nome) > 0){
                break;
            } else if(strcmp(atual->nome, prod->nome) == 0){
                atual->quantidade += prod->quantidade;
                return SUCESSO;
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
    int i;

    std::cout << LIMPA;

    std::cout << FUNDO_BRANCO << "Codigo do Produto: " << p->codigo << LIMPA_FUNDO << std::endl;
    std::cout << FUNDO_BRANCO << "Quantidade do Produto no Estoque: " << p->quantidade << LIMPA_FUNDO << std::endl;
    std::cout << FUNDO_BRANCO << "Preço do Produto: R$" << p->preco << LIMPA_FUNDO << std::endl;
    std::cout << FUNDO_BRANCO << "Nome do Produto: " << p->nome << LIMPA_FUNDO << std::endl;
    
    std::cout << MAGENTA;

    for(i = 0; i < 60; i++){
        std::cout << "=";
    }

    std::cout << LIMPA << std::endl;
}

void IntroducaoEstoque(int tam, const char borda){
    int i;

    //introduçao ====================================================

    for(i = 0; i < 60; i++){
        std::cout << CIANO;
        std::cout << borda;
    }

    std::cout << "\n";

    for(i = 0; i < 24; i++){
        if(i == 0 || i == 1 || i == 2){
            std::cout << borda;
        } else{
            std::cout << " ";
        }
    }

    std::cout << VERMELHO << "ESTOQUE ATUAL";

    for(i = 0; i < 23; i++){
        if(i + 2 == 22 || i + 1 == 22 || i == 22){
            std::cout << CIANO;
            std::cout << borda;
        } else{
            std::cout << " ";
        }
    }

    std::cout << "\n";

    for(i = 0; i < 60; i++){
        std::cout << borda;
    }

    std::cout << "\n" << MAGENTA;

    for(i = 0; i < 60; i++){
        std::cout << "=";
    }

    std::cout << CIANO << "\n-- NUMERO DE PRODUTOS DIFERENTES: " << tam << " --" << LIMPA << "\n";

    std::cout << MAGENTA;

    for(i = 0; i < 60; i++){
        std::cout << "=";
    }

    std::cout << "\n";

    //==========================================================
}

void IntroducaoFila(int tam, const char borda){
    int i;

    //introduçao ====================================================

    for(i = 0; i < 60; i++){
        std::cout << CIANO;
        std::cout << borda;
    }

    std::cout << "\n";

    for(i = 0; i < 22; i++){
        if(i == 0 || i == 1 || i == 2){
            std::cout << borda;
        } else{
            std::cout << " ";
        }
    }

    std::cout << VERMELHO << "LISTA DE PEDIDOS";

    for(i = 0; i < 22; i++){
        if(i + 2 == 21 || i + 1 == 21 || i == 21){
            std::cout << CIANO;
            std::cout << borda;
        } else{
            std::cout << " ";
        }
    }

    std::cout << "\n";

    for(i = 0; i < 60; i++){
        std::cout << borda;
    }

    std::cout << "\n" << MAGENTA;

    for(i = 0; i < 60; i++){
        std::cout << "=";
    }

    std::cout << CIANO << "\n-- NUMERO DE PEDIDOS DIFERENTES: " << tam << " --" << LIMPA << "\n";

    std::cout << MAGENTA;

    for(i = 0; i < 60; i++){
        std::cout << "=";
    }

    std::cout << "\n";

    //==========================================================
}
void IntroducaoPilha(int tam, const char borda){
     int i;

    //introduçao ====================================================

    for(i = 0; i < 60; i++){
        std::cout << CIANO;
        std::cout << borda;
    }

    std::cout << "\n";

    for(i = 0; i < 17; i++){
        if(i == 0 || i == 1 || i == 2){
            std::cout << borda;
        } else{
            std::cout << " ";
        }
    }

    std::cout << VERMELHO << "PILHA DE REABASTECIMENTO";

    for(i = 0; i < 18; i++){
        if(i + 2 == 17 || i + 1 == 17 || i == 17){
            std::cout << CIANO;
            std::cout << borda;
        } else{
            std::cout << " ";
        }
    }

    std::cout << "\n";

    for(i = 0; i < 60; i++){
        std::cout << borda;
    }

    std::cout << "\n" << MAGENTA;

    for(i = 0; i < 60; i++){
        std::cout << "=";
    }

    std::cout << CIANO << "\n-- NUMERO DE PRODUTOS NA PILHA: " << tam << " --" << LIMPA << "\n";

    std::cout << MAGENTA;

    for(i = 0; i < 60; i++){
        std::cout << "=";
    }

    std::cout << "\n";

    //==========================================================
}

void MostrarEstoque(Estoque * est){
    if(est == NULL) return;
    if(est->tamanho == 0){
        std::cout << "ESTOQUE VAZIO\n\n";
        return;
    };

    IntroducaoEstoque(est->tamanho, '#');

    Produto * atual = est->primeiro;
    while(atual != NULL){
        MostrarProduto(atual);
        atual = atual->proximo;
    }
}

Produto * MaquinaProdutos(){
    int codigo, quantidade;
    float preco;
    char nome[TAM_MAX];
    Produto * p = NULL;
    std::cout << "Digite um codigo para seu produto: ";
    std::cin >> codigo;
    std::cout << "Digite um preço para seu produto: ";
    std::cin >> preco;
    std::cout << "Digite a quantidade deste produto: ";
    scanf("%d%*c", &quantidade);
    std::cout << "Digite um nome para seu produto: ";
    LeString(nome);
    p = CriarProduto(codigo, quantidade, nome, preco);
    return p;
}

Pedido * MaquinaPedidos(){
    int quantidade;
    char nome[TAM_MAX];

    Pedido * ped = NULL;

    std::cout << "Digite a quantidade desejada do produto: ";
    scanf("%d%*c", &quantidade);
    std::cout << "Digite o nome do produto desejado: ";
    LeString(nome);

    ped = CriarPedido(nome, quantidade);

    return ped;
}

bool AdicionarPedidoFinal(Fila * f, Pedido * ped){
    if(f == NULL || ped == NULL) return FALHA;
    if(f->primeiro == NULL){
        f->primeiro = ped;
        (f->tamanho)++;
        return SUCESSO;
    } else{
        Pedido * atual = f->primeiro;
        while(atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual->proximo = ped;
        ped->anterior = atual;
        (f->tamanho)++;
        return SUCESSO;
    }

    return FALHA;
}

bool RemoverPedidoInicio(Fila * f){
    if(f == NULL) return FALHA;
    if(f->primeiro == NULL){
        return FALHA;
    } else{
        Pedido * removido = f->primeiro;
        f->primeiro = f->primeiro->proximo;
        if(f->primeiro != NULL){ 
            f->primeiro->anterior = NULL;
        }
        free(removido);
        (f->tamanho)--;
        return SUCESSO;
    }

    return FALHA;
}

bool RemoverEstoque(Estoque * est, Produto * prod){
    if(est == NULL || prod == NULL) return FALHA;
    Produto * atual = est->primeiro;
    if(atual == NULL) return FALHA;
    if(strcmp(atual->nome, prod->nome) == 0){
        est->primeiro = est->primeiro->proximo;
        free(atual);
        (est->tamanho)--;
        return SUCESSO;
    } else{
        while(true){
            if(strcmp(atual->nome, prod->nome) == 0){
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

bool AtendePedidoFila(Estoque * est, Fila * f){
    if(est == NULL || f == NULL) return FALHA;
    Pedido * ped = f->primeiro;
    Produto * atual = est->primeiro;
    if(atual == NULL){
        std::cout << VERMELHO << "ESTOQUE VAZIO\n" << LIMPA;
        return FALHA;
    }
    if(ped == NULL){
        std::cout << VERMELHO << "FILA DE PEDIDOS VAZIA\n" << LIMPA;
        return FALHA;   
    }
    while(true){
        if(strcmp(atual->nome, ped->nome) == 0){
            if(atual->quantidade >= ped->quantidade_pedidos){
                atual->quantidade -= ped->quantidade_pedidos;
                printf("O TOTAL GASTO COM O PEDIDO FOI DE R$%.2f\n", ped->quantidade_pedidos * atual->preco);
                printf("SEU PEDIDO DE (%s) FOI ATENDIDO COM SUCESSO\n", atual->nome);
                RemoverPedidoInicio(f);
                if(atual->quantidade == 0) RemoverEstoque(est, atual);
                return SUCESSO;
            } else {
                std::cout << "IMPOSSIVEL ATENDER O PEDIDO, TEMOS " << atual->quantidade << " ITENS DE (" << atual->nome;
                std::cout << ") E FORAM SOLICITADOS " << ped->quantidade_pedidos << " ITENS, O PEDIDO SERA EXCLUIDO!\n";
                RemoverPedidoInicio(f);
                return FALHA;
            }
         }
         if(atual->proximo == NULL) break;
         atual = atual->proximo;
    }

    std::cout << "IMPOSSIVEL ATENDER O PEDIDO, PRODUTO NÃO FOI ENCONTRADO NO ESTOQUE\n";
    RemoverPedidoInicio(f);
    return FALHA;
}

bool AdicionarProdutoPilha(Pilha * pi, Produto * prod){
    if(pi == NULL || prod == NULL) return FALHA;
    if(pi->ultimo == NULL){
        pi->ultimo = prod;
        (pi->tamanho)++;
        return SUCESSO;
    } else{
        Produto * anterior = pi->ultimo; 
        anterior->proximo = prod;
        prod->anterior = anterior;
        pi->ultimo = prod;
        (pi->tamanho)++;
        return SUCESSO;
    }

    return FALHA;
}

bool RemoverProdutoPilha(Pilha * pi){
    if(pi == NULL) return FALHA;
    if(pi->ultimo == NULL){
        return FALHA;
    } else if(pi->ultimo->proximo == NULL){
        Produto * ultimo = pi->ultimo;
        pi->ultimo = NULL;
        free(ultimo);
        (pi->tamanho)--;
        return SUCESSO;
    } else{
        Produto * ultimo = pi->ultimo;
        Produto * anterior = pi->ultimo->anterior;
        anterior->proximo = NULL;
        pi->ultimo = anterior;
        free(ultimo); 
        (pi->tamanho)--;
        return SUCESSO;
    }

    return FALHA;
}

bool ReabastecerEstoque(Estoque * est, Pilha * pi){
    if(est == NULL || pi == NULL) return FALHA;
    Produto * ultimo = pi->ultimo;
    while(ultimo != NULL){
    Produto * produto_novo = CriarProduto(ultimo->codigo, ultimo->quantidade, ultimo->nome, ultimo->preco);
    AdicionarEstoque(est, produto_novo);
    ultimo = ultimo->anterior;
    RemoverProdutoPilha(pi);
    }

    pi->tamanho = 0;

    return SUCESSO;
}

void MostrarPedido(Pedido * ped){
    if(ped == NULL) return;
    int i;
    char nome[TAM_MAX];

    std::cout << LIMPA;

    std::cout << FUNDO_BRANCO << "Nome do Item do Pedido: " << ped->nome<< LIMPA_FUNDO << std::endl;
    std::cout << FUNDO_BRANCO << "Numero de Unidades Solicitadas no Pedido: " << ped->quantidade_pedidos << LIMPA_FUNDO << std::endl;
    
    std::cout << MAGENTA;

    for(i = 0; i < 60; i++){
        std::cout << "=";
    }

    std::cout << LIMPA << std::endl;
}

void MostrarFila(Fila * f){
    if(f == NULL) return;
    if(f->tamanho == 0){
        std::cout << "FILA DE PEDIDOS VAZIA\n\n";
        return;
    };

    IntroducaoFila(f->tamanho, '|');

    Pedido * atual = f->primeiro;

    while(atual != NULL){
        MostrarPedido(atual);
        atual = atual->proximo;
    }
}

void LinhaVerde(){
    int i;
    std::cout << "\n" << VERDE;

    for(i = 0; i < 60; i++){
        std::cout << "X";
    }

    std::cout << LIMPA << "\n" << std::endl;
}

void MostrarPilha(Pilha * pi){
    if(pi == NULL) return;
    if(pi->tamanho == 0){
        std::cout << "PILHA DE REABASTECIMENTO VAZIA\n\n";
        return;
    };

    IntroducaoPilha(pi->tamanho, '~');

    Produto * atual = pi->ultimo;

    while(atual != NULL){
        MostrarProduto(atual);
        atual = atual->anterior;
    }
}


//===================================================================================
