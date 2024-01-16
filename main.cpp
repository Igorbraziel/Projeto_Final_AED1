#include "estruturas.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>

int main(){
    Estoque * est = CriarEstoque();
    Fila * fila_pedidos = CriarFila();
    Pilha * pilha_reabastecimento = CriarPilha();
    char nome[TAM_MAX];
    int opcao;

    // inicialização do estoque ==================
    strcpy(nome, "Laranja");
    AdicionarEstoque(est, CriarProduto(1, 56, nome, 1.50));

    strcpy(nome, "Melancia");
    AdicionarEstoque(est, CriarProduto(13, 102, nome, 4.00));

    strcpy(nome, "Uva");
    AdicionarEstoque(est, CriarProduto(4, 76, nome, 7.50));

    /*
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

    // inicialização pedidos

    AdicionarPedidoFinal(fila_pedidos, CriarPedido(102, 314));
    AdicionarPedidoFinal(fila_pedidos, CriarPedido(34, 200));

    // inicialização devolucoes

    strcpy(nome, "Pirulito");
    AdicionarProdutoPilha(pilha_reabastecimento, CriarProduto(104, 203, nome));

    strcpy(nome, "Chiclete");
    AdicionarProdutoPilha(pilha_reabastecimento, CriarProduto(111, 453, nome));

    // =============================================

    */

    while(true){
        std::cout << VERMELHO << FUNDO_CINZA << "CENTRAL DE GERENCIAMENTO" << LIMPA_FUNDO << "\n\n";
        std::cout << CIANO << "[1] -" << LIMPA << "(Adicionar Pedido na Fila)\n";
        std::cout << CIANO << "[2] -" << LIMPA << "(Adicionar Produto na Pilha de Reabastecimento)\n";
        std::cout << CIANO << "[3] -" << LIMPA << "(Atender Pedido da Fila)\n";
        std::cout << CIANO << "[4] -" << LIMPA << "(Reabastecer Estoque com Itens da Pilha)\n";
        std::cout << CIANO << "[5] -" << LIMPA << "(Visualizar Estoque)\n";
        std::cout << CIANO << "[6] -" << LIMPA << "(Visualizar Fila de Pedidos)\n";
        std::cout << CIANO << "[7] -" << LIMPA << "(Visualizar Pilha de Itens)\n";
        std::cout << CIANO << "[8] -" << LIMPA << "(Finalizar o Programa)\n\n";
        std::cout << AZUL << "Digite o número da opção desejada: " << LIMPA;
        std::cin >> opcao;
        std::cout << "\n";

        if (opcao == 1){
            AdicionarPedidoFinal(fila_pedidos, MaquinaPedidos());
            sleep(3);
            std::cout << "\n";
        } else if (opcao == 2){
            AdicionarProdutoPilha(pilha_reabastecimento, MaquinaProdutos());
            sleep(3);
            std::cout << "\n";
        } else if (opcao == 3){
            AtendePedidoFila(est, fila_pedidos);
            sleep(3);
            std::cout << "\n";
        } else if (opcao == 4){
            ReabastecerEstoque(est, pilha_reabastecimento); // ESTÁ TENDO FALHAS
            sleep(3);
            std::cout << "\n";
        } else if (opcao == 5){
            MostrarEstoque(est);
            std::cout << std::endl;
            sleep(5);
        } else if (opcao == 6){
            MostrarFila(fila_pedidos);
            std::cout << std::endl;
            sleep(5);
        } else if (opcao == 7){
            MostrarPilha(pilha_reabastecimento);
            std::cout << std::endl;
            sleep(5);
        } else if (opcao == 8){
            std::cout << FUNDO_MAGENTA << "VOLTE SEMPRE !!!" << LIMPA_FUNDO << "\n\n";
            sleep(3);
            break;
        } else{
            std::cout << VERMELHO << "OPÇÃO NÃO DISPONÍVEL\n\n" << LIMPA;
            sleep(3);
        }
    }

    DestruirEstoque(est);
    DestruirFila(fila_pedidos);
    DestruirPilha(pilha_reabastecimento);
    
    return 0;
}
