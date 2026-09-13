#ifndef DUPLA_H
#define DUPLA_H

#include "produto.h"

typedef struct No {
    Produto produto;
    struct No *anterior;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} lista_dupla;

void inicializar_lista(lista_dupla *lista);

void inserir_inicio(lista_dupla *lista, Produto produto);
void inserir_fim(lista_dupla *lista, Produto produto);

void remover_inicio(lista_dupla *lista);
void remover_fim(lista_dupla *lista);
void remover_id(lista_dupla *lista, int id);

void buscar_nome(lista_dupla *lista, char nome[]);
void atualizar_id(lista_dupla *lista, int id);

void exibir_lista(lista_dupla *lista);
void exibir_reverso(lista_dupla *lista);

int contar_lista(lista_dupla *lista);
void esvaziar_lista(lista_dupla *lista);

#endif