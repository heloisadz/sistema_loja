#Sistema de Estoque da Loja de Conveniência

Integrantes:

* Maria Heloisa Dias Santana
* Raissa Gomes Carneiro
* Fernanda Amille Pereira Santos

Sobre o projeto

O projeto consiste em um sistema para gerenciamento do estoque de uma loja de conveniência, desenvolvido em linguagem C.

Foram utilizadas três tipos de listas encadeadas:

Lista simples: produtos perecíveis.
Lista dupla: produtos não perecíveis.
Lista circular: produtos em promoção.

Funcionalidades

O sistema permite:

* Inserir produtos no início e no fim;
* Remover produtos no início, no fim e por ID;
* Buscar produtos pelo nome;
* Atualizar a quantidade;
* Exibir os produtos;
* Contar os produtos;
* Esvaziar a lista.

Na lista dupla também é possível exibir os produtos em ordem reversa.

Arquivos

* `main.c` – menu principal do sistema;
* `produto.c` e `produto.h` – funções dos produtos;
* `simples.c` e `simples.h` – lista simples;
* `dupla.c` e `dupla.h` – lista dupla;
* `circular.c` e `circular.h` – lista circular;
* `Makefile` – compilação do projeto.

Como executar

Para compilar:

```bash
make
```
Para executar:

```bash
./estoque
```
Para limpar os arquivos da compilação:

```bash
make clean
```
Objetivo

O objetivo do projeto é aplicar os conhecimentos de estruturas de dados, listas encadeadas e linguagem C, conforme solicitado na atividade.
