#include <stdio.h>
#include "biblioteca.h"

int main() {
    struct Contato lista_contatos[255]; // Array para armazenar os contatos
    int total_contatos = 0; // Total de contatos atualmente na lista
    char opcao;
    char nome_arquivo[100];

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Deletar contato\n");
        printf("4. Salvar agenda\n");
        printf("5. Carregar agenda\n");
        printf("6. Sair\n");
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
                char telefone[15];
                scanf("%s", telefone);
                deletar_contato(lista_contatos, &total_contatos, telefone);
                break;
            case '4':
                printf("\nDigite o nome do arquivo para salvar a agenda: ");
                scanf("%s", nome_arquivo);
                salvar_agenda(lista_contatos, total_contatos, nome_arquivo);
                break;
            case '5':
                printf("\nDigite o nome do arquivo para carregar a agenda: ");
                scanf("%s", nome_arquivo);
                carregar_agenda(lista_contatos, &total_contatos, nome_arquivo);
                break;
            case '6':
                printf("\nSaindo do programa.\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != '6');

    return 0;
}
//revisado