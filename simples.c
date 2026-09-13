#include "simples.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserir_inicio_simples(NoSimples **lista, Produto produto)
{
    NoSimples *novo = malloc(sizeof(NoSimples));

    if (novo == NULL)
    {
        printf("Erro: falha de alocacao de memoria.\n");
        return;
    }else{
    novo->produto = produto;
    novo->proximo = *lista;
    *lista = novo;
     printf("Produto inserido no inicio.\n");
    }
}

void inserir_fim_simples(NoSimples **lista, Produto produto)
{
    NoSimples *novo = malloc(sizeof(NoSimples));

    if (novo == NULL)
    {
        printf("Erro: falha de alocacao de memoria.\n");
        return;
    }else{

    novo->produto = produto;
    novo->proximo = NULL;

    if (*lista == NULL)
    {
        *lista = novo;
    }
    else
    {
        NoSimples *temp = *lista;

        while (temp->proximo != NULL)
        {
            temp = temp->proximo;
        }

        temp->proximo = novo;
    }

    printf("Produto inserido no fim.\n");
    }
}

void remover_inicio_simples(NoSimples **lista)
{
    if (*lista == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    NoSimples *temp = *lista;
    *lista = temp->proximo;

    free(temp);

    printf("Produto removido do inicio.\n");
}

void remover_fim_simples(NoSimples **lista)
{
    if (*lista == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    if ((*lista)->proximo == NULL)
    {
        free(*lista);
        *lista = NULL;
        printf("Produto removido do fim.\n");
        return;
    }

    NoSimples *temp = *lista;

    while (temp->proximo->proximo != NULL)
    {
        temp = temp->proximo;
    }

    free(temp->proximo);
    temp->proximo = NULL;

    printf("Produto removido do fim.\n");
}

void remover_id_simples(NoSimples **lista, int id)
{
    if (*lista == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    if ((*lista)->produto.id == id)
    {
        NoSimples *remover = *lista;
        *lista = remover->proximo;
        free(remover);

        printf("Produto removido.\n");
        return;
    }

    NoSimples *atual = *lista;

    while (atual->proximo != NULL)
    {
        if (atual->proximo->produto.id == id)
        {
            NoSimples *remover = atual->proximo;

            atual->proximo = remover->proximo;

            free(remover);

            printf("Produto removido.\n");
            return;
        }

        atual = atual->proximo;
    }

    printf("ID inexistente.\n");
}

void buscar_nome_simples(NoSimples *lista, const char *nome)
{
    int encontrou = 0;

    while (lista != NULL)
    {
        if (strstr(lista->produto.nome, nome) != NULL)
        {
            exibir_produto(lista->produto);
            encontrou = 1;
        }

        lista = lista->proximo;
    }

    if (!encontrou)
        printf("Nenhum produto encontrado.\n");
}

void atualizar_simples(NoSimples *lista, int id)
{
    while (lista != NULL)
    {
        if (lista->produto.id == id)
        {
            atualizar_quantidade(&lista->produto);
            return;
        }

        lista = lista->proximo;
    }

    printf("ID inexistente.\n");
}

void exibir_simples(NoSimples *lista)
{
    if (lista == NULL)
    {
        printf("Lista vazia.\n");
        printf("---------------------------\n");
        return;
    }

    while (lista != NULL)
    {
        exibir_produto(lista->produto);
        printf("---------------------------\n");
        lista = lista->proximo;
    }
}

int contar_simples(NoSimples *lista)
{
    int contador = 0;

    while (lista != NULL)
    {
        contador++;
        lista = lista->proximo;
    }

    return contador;
}

void esvaziar_simples(NoSimples **lista)
{
    NoSimples *atual = *lista;

    while (atual != NULL)
    {
        NoSimples *proximo = atual->proximo;

        free(atual);

        atual = proximo;
    }

    *lista = NULL;
}