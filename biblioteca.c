#include "biblioteca.h"
#include <stdio.h>

void adicionar_contato(struct Contato lista_contatos[], int *total_contatos) {
    if (*total_contatos < 255) {
        printf("\nAdicionar Contato:\n");
        printf("Nome: ");
        scanf("%s", lista_contatos[*total_contatos].nome);
        printf("Sobrenome: ");
        scanf("%s", lista_contatos[*total_contatos].sobrenome);
        printf("Email: ");
        scanf("%s", lista_contatos[*total_contatos].email);
        printf("Telefone: ");
        scanf("%s", lista_contatos[*total_contatos].telefone);
        (*total_contatos)++;
        printf("Contato adicionado com sucesso!\n");
    } else {
        printf("\nA lista de contatos esta cheia.\n");
    }
}

void listar_contatos(struct Contato lista_contatos[], int total_contatos) {
    printf("\nLista de Contatos:\n");
    for (int i = 0; i < total_contatos; i++) {
        printf("Nome: %s %s\n", lista_contatos[i].nome, lista_contatos[i].sobrenome);
        printf("Email: %s\n", lista_contatos[i].email);
        printf("Telefone: %s\n\n", lista_contatos[i].telefone);
    }
}