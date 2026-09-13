#ifndef SIMPLES_H
#define SIMPLES_H

#include "produto.h"

typedef struct NoSimples {
    Produto produto;
    struct NoSimples *proximo;
} NoSimples;

void inserir_inicio_simples(NoSimples **lista, Produto produto);
void inserir_fim_simples(NoSimples **lista, Produto produto);

void remover_inicio_simples(NoSimples **lista);
void remover_fim_simples(NoSimples **lista);
void remover_id_simples(NoSimples **lista, int id);

void buscar_nome_simples(NoSimples *lista, const char *nome);
void atualizar_simples(NoSimples *lista, int id);

void exibir_simples(NoSimples *lista);
int contar_simples(NoSimples *lista);
void esvaziar_simples(NoSimples **lista);

#endif