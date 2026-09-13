#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    int id;
    char nome[50];
    int quantidade;
    float preco;
    char validade[11];
} Produto;

void cadastrar_produto(Produto *produto);
void exibir_produto(Produto produto);
void atualizar_quantidade(Produto *produto);

#endif