#include "biblioteca.h"
#include <stdio.h>
#include <string.h>

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

void deletar_contato(struct Contato lista_contatos[], int *total_contatos, char telefone[]) {
    int i, j;
    for (i = 0; i < *total_contatos; i++) {
        if (strcmp(lista_contatos[i].telefone, telefone) == 0) {
            for (j = i; j < *total_contatos - 1; j++) {
                strcpy(lista_contatos[j].nome, lista_contatos[j + 1].nome);
                strcpy(lista_contatos[j].sobrenome, lista_contatos[j + 1].sobrenome);
                strcpy(lista_contatos[j].email, lista_contatos[j + 1].email);
                strcpy(lista_contatos[j].telefone, lista_contatos[j + 1].telefone);
            }
            (*total_contatos)--;
            printf("Contato deletado com sucesso!\n");
            return;
        }
    }
    printf("Contato nao encontrado.\n");
}