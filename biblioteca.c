
#include "biblioteca.h"
#include <stdio.h>

void add_contato(struct Contato lista_contatos[], int *total_contatos) {
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
