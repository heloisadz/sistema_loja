#ifndef CIRCULAR_H
#define CIRCULAR_H
#include "produto.h"

typedef struct{
    Produto produto;
    struct No *prox_item;
}No;

typedef struct {
    No *inicio;
    No *fim;
}Lista_circular;

void inserir_inicio();

void inserir_fim(Lista_circular *lista);

void remover(Lista_circular *lista);

void buscar_por_nome(Lista_circular *lista, char texto[]);
    
void contar_produtos(Lista_circular *lista);

void atualizacao_qtd(Lista_circular *lista, unsigned int idt, unsigned int nova_qtd);

void exibir(Lista_circular *lista);

void esvaziar_lista(Lista_circular *lista);

#endif