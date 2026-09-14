#include <stdio.h>
#include "dupla.h"
#include "simples.h"
#include "circular.h"

void menu_dupla(lista_dupla *lista){
    int opcao;

    do{
        printf("\n===== NAO PERECIVEIS =====\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no fim\n");
        printf("3. Remover do inicio\n");
        printf("4. Remover do fim\n");
        printf("5. Remover por ID\n");
        printf("6. Buscar por nome\n");
        printf("7. Atualizar quantidade\n");
        printf("8. Exibir produtos\n");
        printf("9. Exibir em ordem reversa\n");
        printf("10. Contar produtos\n");
        printf("11. Esvaziar lista\n");
        printf("0. Voltar\n");

       
        printf("---------------------------\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

    
        printf("---------------------------\n");
        
        switch (opcao){
            case 1:{
               Produto produto;

               cadastrar_produto(&produto);
               inserir_inicio(lista, produto);
               
               printf("---------------------------\n");
                break;
            }
            case 2:{
                Produto produto;

                cadastrar_produto(&produto);
                inserir_fim(lista, produto);
                
                printf("---------------------------\n");
                break;
            }
            case 3:{
                remover_inicio(lista);
                
                printf("---------------------------\n");
                break;
            }
            case 4:{
                remover_fim(lista);
                
                printf("---------------------------\n");
                break;
            }
            case 5:{
                int id;
                printf("ID do produto: ");
                scanf("%d", &id);

                remover_id(lista, id);
                
                printf("---------------------------\n");
                break;
            }    
            case 6:{
                char nome[50];

                printf("Nome do produto: ");
                scanf(" %49[^\n]", nome);
                printf("---------------------------\n");
                buscar_nome(lista, nome);
                printf("---------------------------\n");
                
                break;
            }
            case 7:{
                int id;
                printf("ID do produto: ");
                scanf("%d", &id);
                printf("\n");
                atualizar_id(lista, id);
                
                printf("---------------------------\n");
                break;
            }    
            case 8:{
                exibir_lista(lista);
                printf("Fim da listagem!\n");
                printf("---------------------------\n");
                break;
            }    
            case 9:{
                exibir_reverso(lista);
                printf("Fim da listagem!\n");
                printf("---------------------------\n");
                break;
            }    
            case 10:{
                printf("Quantidade de produtos: %d\n", contar_lista(lista));
                printf("---------------------------\n");
                break;
            }    
            case 11:{
                esvaziar_lista(lista);
                printf("Lista esvaziada!\n");
                printf("---------------------------\n");
                break;
            }    
            case 0:{
                break;
            }    
            default:
                printf("Opcao invalida!\n");
        }
    }while(opcao!=0);
}

void menu_simples(NoSimples **lista){
    int opcao;
    do{
        printf("\n===== PERECIVEIS =====\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no fim\n");
        printf("3. Remover do inicio\n");
        printf("4. Remover do fim\n");
        printf("5. Remover por ID\n");
        printf("6. Buscar por nome\n");
        printf("7. Atualizar quantidade\n");
        printf("8. Exibir produtos\n");
        printf("9. Contar produtos\n");
        printf("10. Esvaziar lista\n");
        printf("0. Voltar\n");

        printf("---------------------------\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        printf("---------------------------\n");

        switch (opcao){
            case 1:{
                Produto produto;

                cadastrar_produto(&produto);
                inserir_inicio_simples(lista, produto);
                
                printf("---------------------------\n");
                break;
            }
            case 2:{
                Produto produto;

                cadastrar_produto(&produto);
                inserir_fim_simples(lista, produto);
                
                printf("---------------------------\n");
                break;
            }
            case 3:{
                remover_inicio_simples(lista);
                
                printf("---------------------------\n");
                break;
            }
            case 4:{
                remover_fim_simples(lista);
                
                printf("---------------------------\n");
                break;
            }
            case 5:{
                int id;

                printf("ID do produto: ");
                scanf("%d", &id);

                remover_id_simples(lista, id);
                
                printf("---------------------------\n");
                break;
            }

            case 6:{
                char nome[50];

                printf("Nome do produto: ");
                scanf(" %49[^\n]", nome);
                printf("---------------------------\n");
                buscar_nome_simples(*lista, nome);
                printf("---------------------------\n");
                break;
            }
            case 7:{
                int id;

                printf("ID do produto: ");
                scanf("%d", &id);

                atualizar_simples(*lista, id);
                printf("---------------------------\n");
                printf("Quantidade alterada!\n");
                printf("---------------------------\n");
                break;
            }
            case 8:{
                exibir_simples(*lista);
                printf("Fim da listagem!\n");
                printf("---------------------------\n");
                break;
            }
            case 9:{
                printf("Quantidade de produtos: %d\n",
                       contar_simples(*lista));
                printf("---------------------------\n");
                break;
            }
            case 10:{
                esvaziar_simples(lista);
                printf("Lista esvaziada!\n");
                printf("Lista esvaziada!\n");
                printf("---------------------------\n");
                break;
            }
            case 0:{
                break;
            }
            default:{
                printf("Opcao invalida!\n");
            }
        }
    } while (opcao != 0);
}

void menu_circular(Lista_circular *lista){
    int opcao;

    do{
        printf("\n===== PROMOCOES =====\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no fim\n");
        printf("3. Remover do inicio\n");
        printf("4. Remover do fim\n");
        printf("5. Remover por ID\n");
        printf("6. Buscar por nome\n");
        printf("7. Atualizar quantidade\n");
        printf("8. Exibir produtos\n");
        printf("9. Contar produtos\n");
        printf("10. Esvaziar lista\n");
        printf("0. Voltar\n");

        printf("---------------------------\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        printf("---------------------------\n");

        switch(opcao){

            case 1:{
                Produto produto;

                cadastrar_produto(&produto);
                inserir_inicio_circular(lista, produto);

                printf("---------------------------\n");
                break;
            }

            case 2:{
                Produto produto;

                cadastrar_produto(&produto);
                inserir_fim_circular(lista, produto);

                printf("---------------------------\n");
                break;
            }

            case 3:{
                remover_inicio_circular(lista);

                printf("---------------------------\n");
                break;
            }

            case 4:{
                remover_fim_circular(lista);

                printf("---------------------------\n");
                break;
            }

            case 5:{
                int id;

                printf("ID do produto: ");
                scanf("%d", &id);

                remover_por_id(lista, id);

                printf("---------------------------\n");
                break;
            }

            case 6:{
                char nome[50];

                printf("Nome do produto: ");
                scanf(" %49[^\n]", nome);

                printf("---------------------------\n");
                buscar_por_nome(lista, nome);
                printf("---------------------------\n");

                break;
            }

            case 7:{
                int id;
                

                printf("ID do produto: ");
                scanf("%d", &id);
                printf("\n");
                atualizacao_qtd(lista, id);

                printf("---------------------------\n");
                break;
            }

            case 8:{
                exibir(lista);

                printf("Fim da listagem!\n");
                printf("---------------------------\n");
                break;
            }

            case 9:{
                contar_produtos(lista);

                printf("Quantidade de produtos: %d\n", contar_produtos(lista));
                printf("---------------------------\n");
                break;
            }

            case 10:{
                esvaziar_circular(lista);

                printf("Lista esvaziada!\n");
                printf("---------------------------\n");
                break;
            }

            case 0:{
                break;
            }

            default:{
                printf("Opcao invalida!\n");
            }
        }

    }while(opcao != 0);
}


int main()
{
    NoSimples *lista_simples = NULL;

    lista_dupla lista_dupla;
    inicializar_lista(&lista_dupla);

    Lista_circular lista_circular;
    lista_circular.inicio = NULL;
    lista_circular.fim = NULL;

    int opcao;

    do{
        printf("\n===== ESTOQUE DA LOJA =====\n");
        printf("1. Gerenciar Pereciveis (Simples)\n");
        printf("2. Gerenciar Nao Pereciveis (Dupla)\n");
        printf("3. Gerenciar Promocoes (Circular)\n");
        printf("0. Sair\n");

        printf("---------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("---------------------------\n");

        switch (opcao)
        {
            case 1:
                menu_simples(&lista_simples);
                break;

            case 2:
                menu_dupla(&lista_dupla);
                break;

            case 3:
                menu_circular(&lista_circular);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    esvaziar_simples(&lista_simples);
    esvaziar_lista(&lista_dupla);
    esvaziar_circular(&lista_circular);

    return 0;
}