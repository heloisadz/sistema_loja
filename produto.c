#include <stdio.h>
#include "produto.h"

void cadastrar_produto(Produto *produto){
    static int proximo_id = 1;

    produto->id = proximo_id;
    proximo_id++;

    printf("Nome do produto: ");
    scanf(" %49[^\n]", produto->nome);

    printf("Quantidade do produto: ");
    scanf("%d", &produto->quantidade);

    printf("Preco do produto: ");
    scanf("%f", &produto->preco);

    printf("Validade do produto: ");
    scanf(" %10[^\n]", produto->validade);
}

void exibir_produto(Produto produto){
    printf("ID: %d\n", produto.id);
    printf("Nome: %s\n", produto.nome);
    printf("Quantidade: %d\n", produto.quantidade);
    printf("Preco: %.2f\n", produto.preco);
    printf("Validade: %s\n", produto.validade);
}
void atualizar_quantidade(Produto *produto){
    printf("Quantidade atual: %d\n", produto->quantidade);

    printf("Nova quantidade: ");
    scanf("%d", &produto->quantidade);

    printf("Quantidade atualizada!!\n");
}