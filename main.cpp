#include "estruturas.hpp"
#include <iostream>
#include <stdlib.h>

int main(){
    Estoque * est = CriarEstoque();
    Produto * p = NULL;
    int i;

    for(i = 0; i < 3; i++){
        p = MaquinaProdutos();
        AdicionarEstoque(est, p);
    }

    MostrarEstoque(est);

    DestruirEstoque(est);
    
    return 0;
}