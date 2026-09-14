#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "circular.h"
#include "produto.h"

bool estaVazia(Lista_circular *lista){
    if(lista->inicio == NULL){
        return true;
    }else{
        return false;
    }
}

void inserir_inicio_circular(Lista_circular *lista, Produto prod){
    No_circular *novo = malloc(sizeof(No_circular));
    if(novo == NULL){
        printf("Erro ao alocar memoria!");
        return;
    }
    novo->produto = prod;
    novo->prox_item = lista->inicio;

    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
        novo->prox_item = novo;
    }else{
        lista->inicio = novo;
        lista->fim->prox_item = lista->inicio;
        }

    printf("---------------------------\n");
    printf("Produto inserido");
}

void inserir_fim_circular(Lista_circular *lista, Produto prod){
    No_circular *novo = malloc(sizeof(No_circular));
    if(novo == NULL){
        printf("Erro ao alocar memoria!");
        return;
    }
    novo->produto = prod;
    novo->prox_item = lista->inicio;

    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
        novo->prox_item = novo;
    }else{
        lista->fim->prox_item = novo;
        novo->prox_item = lista->inicio;
        lista->fim = novo;
        }

    printf("---------------------------\n");
    printf("Produto inserido");
};

void remover_inicio_circular(Lista_circular *lista){
        if(!estaVazia(lista)){
            No_circular *aux = lista->inicio;

                if(lista->inicio == lista->fim){
                    lista->inicio = NULL;
                    lista->fim = NULL;

                }else{
                    lista->inicio = aux->prox_item;
                    lista->fim->prox_item = lista->inicio;
                }       
                free(aux);
                printf("Produto removido com sucesso!");
                
        }else{
            printf("Lista vazia");
        return;
            
        }
};


void remover_fim_circular(Lista_circular *lista){
        if(!estaVazia(lista)){
            No_circular *aux = lista->inicio;
            No_circular *liberado = lista->fim;

                if(lista->inicio == lista->fim){
                    lista->inicio = NULL;
                    lista->fim = NULL;

                }else{

                    while(aux->prox_item != liberado){
                        aux = aux->prox_item;
                    }
                    aux->prox_item = lista->inicio;
                    lista->fim = aux;
                    free(liberado);
                    }
                    printf("Produto removido com sucesso!");
                                      
        }else{
            printf("Lista vazia");
        return;       
    }
};

void remover_por_id(Lista_circular *lista, int idt){
    if(!estaVazia(lista)){
        No_circular *aux = lista->inicio;
        No_circular *seguinte = aux->prox_item;
        bool encontrado = 0;

        if(aux->produto.id == idt){
            remover_inicio_circular(lista);
            encontrado = 1;
        }else{
            while(seguinte != lista->inicio){
                if(seguinte->produto.id == idt){

                    if(seguinte == lista->fim){
                        remover_fim_circular(lista);
                        seguinte = lista->inicio;
                        encontrado = 1;
                    }else{
                        aux->prox_item = seguinte->prox_item;
                        No_circular *liberado = seguinte;
                        seguinte = seguinte->prox_item;
                        free(liberado);
                        encontrado = 1;
                    }
                    printf("Produto removido com sucesso!");
                }else{
                    aux = seguinte;
                    seguinte = seguinte->prox_item;
                     }
            }
        }

        if(!encontrado){
            printf("ID nao encontrado!");
        }

    }else{
        printf("Lista vazia");
    return;
    }
}

void buscar_por_nome(Lista_circular *lista, char texto[50]){
    if(!estaVazia(lista)){
            No_circular *aux = lista->inicio;
            char *verificar;
            bool encontrado = 0;

            do{
                verificar = strstr(aux->produto.nome, texto);
                if(verificar!= NULL){
                    exibir_produto(aux->produto);
                    encontrado = 1;
                }

                aux = aux->prox_item;

            }while(aux != lista->inicio);

            if(!encontrado){
                    printf("Texto nao encontrado");
            }
            
    }else{
            printf("Lista vazia");
    return;
        }
};

int contar_produtos(Lista_circular *lista){
    int tamanho = 0;
    if(!estaVazia(lista)){
        tamanho++;
        No_circular *aux = lista->inicio;
        while(aux->prox_item != lista->inicio){
            tamanho++;
            aux = aux->prox_item;
        }
        return tamanho;
    }else{
        return tamanho;
    }
};

void atualizacao_qtd(Lista_circular *lista, int idt, int nova_qtd){
    if(!estaVazia(lista)){
        No_circular *aux = lista->inicio;
        do{
            if(aux->produto.id == idt){
                atualizar_quantidade(&aux->produto);
                return;
            }

            aux = aux->prox_item;

        }while(aux != lista->inicio);
    }else{
        printf("Lista vazia");
    return;
    }
   
};
    
void exibir(Lista_circular *lista){
    if(!estaVazia(lista)){
        No_circular *aux = lista->inicio;
        do{
            exibir_produto(aux->produto);

            aux = aux->prox_item;
        }while(aux != lista->inicio);
              
    }else{
        printf("Lista vazia");
    return;
    }
}

void esvaziar_circular(Lista_circular *lista){
    if(!estaVazia(lista)){
        No_circular *aux = lista->inicio;
        No_circular *liberado;
        bool confirmar= 0;
        while(aux->prox_item != lista->inicio){
            liberado = aux;
            aux = aux->prox_item;
            free(liberado);
            confirmar= 1;
        }
        free(aux);

        lista->inicio =NULL;
        lista->fim =NULL;

        if(confirmar){
            printf("Lista esvaziada com sucesso");
        }
    }else{
        printf("Lista vazia");
    return; 

    }
}

