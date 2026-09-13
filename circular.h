#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    unsigned int id;
    char nome[50];
    unsigned int qtd;
    float preco;
    char validade[10];
    struct Produto *prox_item;
}Produto;

void inserir_inicio();

void inserir_fim(Produto *inicio);

void remover(Produto *inicio);

void buscar_por_nome(Produto *inicio, char texto[]);
    
void contar_produtos(Produto *inicio);

void atualizacao_qtd(Produto *inicio, unsigned int idt, unsigned int nova_qtd);

void exibir(Produto *inicio);

void esvaziar_lista(Produto *inicio);

#endif