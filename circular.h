#ifndef CIRCULAR_H
#define CIRCULAR_H
#include "produto.h"

typedef struct No_circular{
    Produto produto;
    struct No_circular *prox_item;
}No_circular;

typedef struct {
    No_circular *inicio;
    No_circular *fim;
}Lista_circular;

void inserir_inicio_circular(Lista_circular *lista, Produto produto);

void inserir_fim_circular(Lista_circular *lista, Produto produto);

void remover_inicio_circular(Lista_circular *lista);

void remover_fim_circular(Lista_circular *lista);

void remover_por_id(Lista_circular *lista, int idt);

void buscar_por_nome(Lista_circular *lista, char texto[]);
    
int contar_produtos(Lista_circular *lista);

void atualizacao_qtd(Lista_circular *lista, int idt, int nova_qtd);

void exibir(Lista_circular *lista);

void esvaziar_circular(Lista_circular *lista);

bool estaVazia(Lista_circular *lista);

#endif