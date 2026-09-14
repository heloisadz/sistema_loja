#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "circular.h"
#include "produto.h"


void inserir_inicio();
void inserir_fim(Lista_circular *inicio){

};

void remover_inicio(Lista_circular *lista){
    if(!estaVazia(lista)){
        No *aux = lista->inicio;
        do{
            

            aux = aux->prox_item;

        }while(aux != lista->inicio);
};
}

void buscar_por_id(Lista_circular *lista, unsigned int idt){
    if(!estaVazia(lista)){
            No *aux = lista->inicio;
            bool encontrado = 0;

            do{
                if(aux->produto.id == idt){
                    printf("Produto encontrado com Sucesso");
                    exibir_produto(aux);
                    encontrado = 1;
                }

                aux = aux->prox_item;

            }while(aux != lista->inicio);

            if(!encontrado){
                    printf("ID nao encontrado");
            }
            
    }else{
            return printf("Lista vazia");
        }
};

void buscar_por_nome(Lista_circular *lista, char texto[50]){
    if(!estaVazia(lista)){
            No *aux = lista->inicio;
            char *verificar;
            bool encontrado = 0;

            do{
                verificar = strstr(aux->produto.nome, texto);
                if(verificar!= NULL){
                    printf("texto encontrado com Sucesso!");
                    exibir_produto(aux);
                    encontrado = 1;
                }

                aux = aux->prox_item;

            }while(aux != lista->inicio);

            if(!encontrado){
                    printf("Texto nao encontrado");
            }
            
    }else{
            return printf("Lista vazia");
        }
};

void contar_produtos(Lista_circular *lista){
    int tamanho = 0;
    if(!estaVazia(lista)){
        tamanho++;
        No *aux = lista->inicio;
        while(aux->prox_item != lista->inicio){
            tamanho++;
            aux = aux->prox_item;
        }
        return tamanho;
    }else{
        return tamanho;
    }
};

void atualizacao_qtd(Lista_circular *lista, unsigned int idt, unsigned int nova_qtd){
    if(!estaVazia(lista)){
        No *aux = lista->inicio;
        do{
            if(aux->produto.id == idt){
                aux->produto.qtd = nova_qtd;
                return;
            }

            aux = aux->prox_item;

        }while(aux != lista->inicio);
    }else{
        return printf("Lista vazia");
    }
   
};
    
void exibir_produto(Lista_circular *lista){
    if(!estaVazia(lista)){
        No *aux = lista->inicio;
        do{
            printf("ID: %d\n", aux->produto.id);
            printf("Nome: %s\n", aux->produto.nome);
            printf("Quantidade: %d\n", aux->produto.qtd);
            printf("Preco: %.2f\n\n", aux->produto.preco);
            printf("Validade: %s\n", aux->produto.validade);

            aux = aux->prox_item;
        }while(aux != lista->inicio);
              
    }else{
        return printf("Lista vazia");
    }
}

void esvaziar_lista(Lista_circular *lista){
    if(!estaVazia(lista)){
        No *aux = lista->inicio;
        No *liberado;
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
        printf("Lista Vazia");

    }
}

bool estaVazia(Lista_circular *lista){
    if(lista->inicio == NULL){
        return true;
    }else{
        return false;
    }
}

