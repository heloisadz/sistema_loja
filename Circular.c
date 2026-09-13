#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "circular.h"

void inserir_inicio();
void inserir_fim(Produto *inicio){

};

void remover;
void buscar_por_nome(Produto *inicio, char texto[50]){
    if(!estaVazia(inicio)){
            Produto *aux = inicio;
            char *verificar;
            verificar = strstr(aux->nome, texto);

            if(verificar!= NULL){
                printf("texto encontrado com Sucesso!, ");
            }
        }else{
            return printf("Lista vazia");
        }
};

void contar_produtos(Produto *inicio){
    int tamanho = 0;
    if(!estaVazia(inicio)){
        tamanho++;
        Produto *aux = inicio;
        while(aux->prox_item != aux){
            tamanho++;
            aux = aux->prox_item;
        }
        return tamanho;
    }else{
        return tamanho;
    }
};

void atualizacao_qtd(Produto *inicio, unsigned int idt, unsigned int nova_qtd){
    if(!estaVazia(inicio)){
        Produto *aux = inicio;
        do{
            if(aux->id == idt){
                aux->qtd = nova_qtd;
                return;
            }

            aux = aux->prox_item;

        }while(aux != inicio);
    }else{
        return printf("Lista vazia");
    }
   
};
    
void exibir(Produto *inicio){
    if(!estaVazia(inicio)){
        Produto *aux = inicio;
        do{
            printf("ID: %d\n", aux->id);
            printf("Nome: %s\n", aux->nome);
            printf("Quantidade: %d\n", aux->qtd);
            printf("Preco: %.2f\n\n", aux->preco);
            printf("Validade: %s\n", aux->validade);

            aux = aux->prox_item;
        }while(aux != inicio);
              
    }else{
        return printf("Lista vazia");
    }
}

void esvaziar_lista(Produto *inicio);

bool estaVazia(Produto *inicio){
    if(inicio == NULL){
        return true;
    }else{
        return false;
    }
}

