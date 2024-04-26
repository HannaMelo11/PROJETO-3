#include <stdio.h>
#include "biblioteca.h"

int main() {
    struct Contato lista_contatos[255]; // Array para armazenar os contatos
    int total_contatos = 0; // Total de contatos atualmente na lista
    char opcao;
    char telefone[15];

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Deletar contato\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                adicionar_contato(lista_contatos, &total_contatos);
                break;
            case '2':
                listar_contatos(lista_contatos, total_contatos);
                break;
            case '3':
                printf("\nDigite o telefone do contato a ser deletado: ");
                scanf("%s", telefone);
                deletar_contato(lista_contatos, &total_contatos, telefone);
                break;
            case '4':
                printf("\nSaindo do programa.\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != '4');

    return 0;
}