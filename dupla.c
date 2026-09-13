#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dupla.h"

void inicializar_lista(lista_dupla *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
}

void inserir_inicio(lista_dupla *lista, Produto produto){
    No *novo = malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao alocar memoria!");
        return;
    }

    novo->produto = produto; // (*No).produto
    novo->anterior = NULL;
    novo->proximo = lista->inicio;

    if(lista->inicio ==NULL){
        lista->inicio = novo;
        lista->fim = novo;
    } else{
        lista->inicio->anterior = novo;
        lista->inicio = novo;
    }
}

void inserir_fim(lista_dupla *lista, Produto produto){
    No *novo = malloc(sizeof(No));

    if(novo == NULL){
        printf("Erro ao alocar memoria!");
        return;
    }

    novo->produto = produto;
    novo->proximo = NULL;
    novo->anterior= lista->fim;

    if(lista->fim == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        lista->fim->proximo = novo;
        lista->fim = novo;
    }

}
void exibir_lista(lista_dupla *lista){
    No *atual = lista->inicio;

    if (atual == NULL){
        printf("Lista vazia.\n");
        printf("---------------------------\n");
        return;
    }
    while (atual != NULL){
        exibir_produto(atual->produto);
        printf("---------------------------\n");
        atual = atual->proximo;
    }
}
void exibir_reverso(lista_dupla *lista){
    No *atual = lista->fim;

    if (atual == NULL){
        printf("Lista vazia.\n");
        return;
    }
    while (atual != NULL){
        exibir_produto(atual->produto);
        printf("---------------------------\n");
        atual = atual->anterior;
    }
}
int contar_lista(lista_dupla *lista){
    int contador = 0;
    No *atual = lista->inicio;

    while (atual != NULL){
        contador++;
        atual = atual->proximo;
    }
    return contador;
}
void remover_inicio(lista_dupla *lista){
    if (lista->inicio == NULL){
        printf("Lista ja esta vazia.\n");
        return;
    }
    No *removido = lista->inicio;

    if (lista->inicio == lista->fim){
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        lista->inicio = lista->inicio->proximo;
        lista->inicio->anterior = NULL;
    }
    free(removido);
}
void remover_fim(lista_dupla *lista){
    if (lista->fim == NULL){
        printf("Lista vazia.\n");
        return;
    }
    No *removido = lista->fim;

    if (lista->inicio == lista->fim){
        lista->inicio = NULL;
        lista->fim = NULL;
    } else{
        lista->fim = lista->fim->anterior;
        lista->fim->proximo = NULL;
    }
    free(removido);
}
void remover_id(lista_dupla *lista, int id){
    No *atual = lista->inicio;

    while (atual != NULL && atual->produto.id != id){
        atual = atual->proximo;
    }
    if (atual == NULL){
        printf("Produto nao encontrado!\n");
        return;
    }
    if (atual == lista->inicio){
        remover_inicio(lista);
        return;
    }
    if (atual == lista->fim){
        remover_fim(lista);
        return;
    }
    atual->anterior->proximo = atual->proximo;
    atual->proximo->anterior = atual->anterior;

    free(atual);
}
void buscar_nome(lista_dupla *lista, char nome[]){
    No *atual = lista->inicio;
    int encontrou = 0;

    while (atual != NULL){
        if (strstr(atual->produto.nome, nome) != NULL){
            exibir_produto(atual->produto);
            printf("\n");
            encontrou = 1;
        }
        atual = atual->proximo;
    }
    if (encontrou == 0){
        printf("Nenhum produto encontrado.\n");
    }
}
void atualizar_id(lista_dupla *lista, int id){
    No *atual = lista->inicio;

    while (atual != NULL){
        if (atual->produto.id == id){
            int nova_quantidade;
            printf("Nova quantidade: ");
            scanf("%d", &nova_quantidade);

            atualizar_quantidade(&atual->produto, nova_quantidade);
            return;
        }
        atual = atual->proximo;
    }
    printf("Produto nao encontrado!\n");
}
void esvaziar_lista(lista_dupla *lista){
    No *atual = lista->inicio;

    while (atual != NULL){
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
}