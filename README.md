# Projeto_Final_AED1
projeto final da disciplina Algoritmo e Estrutura de Dados 1

Sistema de Gerenciamento de Armazém:
Estoque (Lista): Representará o estoque do armazém. Cada item no estoque terá informações como código do produto, nome, quantidade em estoque, etc. Pode ser implementado como uma lista duplamente encadeada.

Pedidos (Fila): Os pedidos dos clientes serão armazenados em uma fila. Cada pedido terá informações como número do pedido, quantidade, etc.

Itens Devolvidos (Pilha): Quando um cliente devolve um item, ele é adicionado a uma pilha. Essa pilha pode ser usada para processar devoluções e, se necessário, reabastecer o estoque.

Aqui estão algumas funcionalidades que você pode implementar:

Adicionar produtos ao estoque.
Remover produtos do estoque quando atendendo um pedido.
Processar pedidos da fila, atualizando o estoque.
Aceitar devoluções de clientes e colocar os itens devolvidos na pilha.
Reabastecer o estoque usando itens da pilha de devoluções.
Visualizar o estado atual do estoque.
Visualizar a lista de pedidos pendentes.
Visualizar os itens devolvidos recentemente.
Além disso, você pode adicionar recursos adicionais, como:

Rastreamento de produtos (quando foi adicionado, quando foi vendido, etc.)
