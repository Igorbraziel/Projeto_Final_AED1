#include "estruturas.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstring>

int main(){
    Estoque * est = CriarEstoque();
    char nome[TAM_MAX];

    strcpy(nome, "Laranja");
    AdicionarEstoque(est, CriarProduto(1, 56, nome));

    strcpy(nome, "erro");
    AdicionarEstoque(est, CriarProduto(1, 6, nome));

    strcpy(nome, "Melancia");
    AdicionarEstoque(est, CriarProduto(13, 102, nome));

    strcpy(nome, "Uva");
    AdicionarEstoque(est, CriarProduto(4, 76, nome));

    strcpy(nome, "Abacate");
    AdicionarEstoque(est, CriarProduto(16, 203, nome));

    strcpy(nome, "Chocolate");
    AdicionarEstoque(est, CriarProduto(22, 534, nome));

    MostrarEstoque(est);

    DestruirEstoque(est);
    
    return 0;
}