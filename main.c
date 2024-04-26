#include <stdio.h>
#include "biblioteca.h"

int main() {
    struct Contato lista_contatos[255]; // Array para armazenar os contatos
    int total_contatos = 0; // Total de contatos atualmente na lista
    char opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar contato\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                add_contato(lista_contatos, &total_contatos);
                break;
            case '2':
                printf("\nSaindo do programa.\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != '2');

    return 0;
}
