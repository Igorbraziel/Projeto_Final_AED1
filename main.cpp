#include "estruturas.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstring>

int main(){
    Estoque * est = CriarEstoque();
    Fila * fila_pedidos = CriarFila();
    char nome[TAM_MAX];

    // inicialização do estoque ==================

    strcpy(nome, "Laranja");
    AdicionarEstoque(est, CriarProduto(1, 56, nome));

    strcpy(nome, "Melancia");
    AdicionarEstoque(est, CriarProduto(13, 102, nome));

    strcpy(nome, "Uva");
    AdicionarEstoque(est, CriarProduto(4, 76, nome));

    strcpy(nome, "Abacate");
    AdicionarEstoque(est, CriarProduto(16, 203, nome));

    strcpy(nome, "Barra de chocolate");
    AdicionarEstoque(est, CriarProduto(22, 534, nome));

    strcpy(nome, "Requeijão");
    AdicionarEstoque(est, CriarProduto(42, 432, nome));

    strcpy(nome, "Creme Dental");
    AdicionarEstoque(est, CriarProduto(34, 344, nome));

    strcpy(nome, "Pão de queijo");
    AdicionarEstoque(est, CriarProduto(77, 78, nome));

    strcpy(nome, "Coca-Cola");
    AdicionarEstoque(est, CriarProduto(10, 254, nome));

    strcpy(nome, "Fanta");
    AdicionarEstoque(est, CriarProduto(102, 314, nome));

    // =============================================
    // inicialização pedidos

    AdicionarPedidoFinal(fila_pedidos, CriarPedido(34, 200));
    AdicionarPedidoFinal(fila_pedidos, CriarPedido(102, 314));


    // =============================================

    MostrarFila(fila_pedidos);
    AtendePedidoFila(est, fila_pedidos);
    AtendePedidoFila(est, fila_pedidos);
    LinhaVerde();
    MostrarEstoque(est);


    DestruirEstoque(est);
    DestruirFila(fila_pedidos);
    
    return 0;
}