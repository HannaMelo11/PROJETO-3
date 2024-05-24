#include "biblioteca.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int validar_email(const char *email) {
    int i, atFound = 0;
    int len = strlen(email);

    // Verificar se o email possui pelo menos um caracter antes do '@'
    if (len < 3)
        return 0;

    // Verificar se há apenas um '@'
    for (i = 0; i < len; i++) {
        if (email[i] == '@') {
            if (atFound)
                return 0; // Mais de um '@' encontrado
            atFound = 1;
        }
    }
    if (!atFound)
        return 0; // Nenhum '@' encontrado

    // Verificar se há pelo menos um caracter após o último '.' após o '@'
    for (i = 0; i < len; i++) {
        if (email[i] == '@') {
            for (int j = i + 1; j < len - 1; j++) {
                if (email[j] == '.')
                    return 1; // Email válido
            }
            return 0; // Nenhum '.' encontrado após o '@'
        }
    }
    return 0; // Caso de falha inesperada
}

void adicionar_contato(struct Contato lista_contatos[], int *total_contatos) {
    if (*total_contatos < 255) {
        printf("\nAdicionar Contato:\n");

        // Limpar o buffer de entrada
        while(getchar() != '\n');

        printf("Nome: ");
        fgets(lista_contatos[*total_contatos].nome, 50, stdin);

        printf("Sobrenome: ");
        fgets(lista_contatos[*total_contatos].sobrenome, 50, stdin);

        // Obter e validar o email
        int email_valido = 0;
        while (!email_valido) {
            printf("Email: ");
            fgets(lista_contatos[*total_contatos].email, 100, stdin);
            lista_contatos[*total_contatos].email[strcspn(lista_contatos[*total_contatos].email, "\n")] = 0; // Remover o caractere de nova linha do final
            email_valido = validar_email(lista_contatos[*total_contatos].email);
            if (!email_valido)
                printf("Email invalido. Tente novamente.\n");
        }

        // Obter telefone
        char telefone[15];
        int valid = 0;
        while (!valid) {
            printf("Telefone: ");
            fgets(telefone, 15, stdin);
            // Verificar se contém apenas dígitos
            valid = 1;
            for (int i = 0; i < strlen(telefone) - 1; i++) {
                if (!isdigit(telefone[i])) {
                    valid = 0;
                    printf("Numero de telefone invalido. Tente novamente.\n");
                    break;
                }
            }
            // Verificar se o telefone já existe na lista de contatos
            for (int i = 0; i < *total_contatos; i++) {
                if (strcmp(lista_contatos[i].telefone, telefone) == 0) {
                    valid = 0;
                    printf("Este telefone ja esta em uso. Tente novamente.\n");
                    break;
                }
            }
        }
        strcpy(lista_contatos[*total_contatos].telefone, telefone);

        (*total_contatos)++;
        printf("Contato adicionado com sucesso!\n");
    } else {
        printf("\nA lista de contatos esta cheia.\n");
    }
}

void listar_contatos(struct Contato lista_contatos[], int total_contatos) {
    printf("\nLista de Contatos:\n");
    for (int i = 0; i < total_contatos; i++) {
        printf("Nome: %s", lista_contatos[i].nome);
        printf("Sobrenome: %s", lista_contatos[i].sobrenome);
        printf("Email: %s", lista_contatos[i].email);
        printf("Telefone: %s\n\n", lista_contatos[i].telefone);
    }
}

void deletar_contato(struct Contato lista_contatos[], int *total_contatos, char telefone[]) {
    int encontrado = 0;

    // Remover espaços em branco e caracteres extras do número de telefone fornecido
    int len = strlen(telefone);
    for (int i = 0; i < len; i++) {
        if (telefone[i] == ' ' || telefone[i] == '\n' || telefone[i] == '\r') {
            for (int j = i; j < len; j++) {
                telefone[j] = telefone[j + 1];
            }
            len--;
            i--;
        }
    }

    // Comparar cada número de telefone na lista de contatos com o número fornecido
    for (int i = 0; i < *total_contatos; i++) {
        char clean_telefone[15]; // Número de telefone limpo (sem espaços em branco ou caracteres extras)
        int clean_index = 0;
        for (int j = 0; j < strlen(lista_contatos[i].telefone); j++) {
            if (!isspace(lista_contatos[i].telefone[j])) {
                clean_telefone[clean_index++] = lista_contatos[i].telefone[j];
            }
        }
        clean_telefone[clean_index] = '\0'; // Adicionar terminador de string

        if (strcmp(clean_telefone, telefone) == 0) {
            encontrado = 1;
            // Substituir o contato a ser deletado pelo último contato na lista
            strcpy(lista_contatos[i].nome, lista_contatos[*total_contatos - 1].nome);
            strcpy(lista_contatos[i].sobrenome, lista_contatos[*total_contatos - 1].sobrenome);
            strcpy(lista_contatos[i].email, lista_contatos[*total_contatos - 1].email);
            strcpy(lista_contatos[i].telefone, lista_contatos[*total_contatos - 1].telefone);
            // Limpar o último contato na lista
            strcpy(lista_contatos[*total_contatos - 1].nome, "");
            strcpy(lista_contatos[*total_contatos - 1].sobrenome, "");
            strcpy(lista_contatos[*total_contatos - 1].email, "");
            strcpy(lista_contatos[*total_contatos - 1].telefone, "");
            (*total_contatos)--;
            printf("Contato deletado com sucesso!\n");
            break;
        }
    }

    if (!encontrado)
        printf("Contato com o telefone %s nao encontrado.\n", telefone);
}


void salvar_agenda(struct Contato lista_contatos[], int total_contatos, char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    fwrite(&total_contatos, sizeof(int), 1, arquivo);
    fwrite(lista_contatos, sizeof(struct Contato), total_contatos, arquivo);
    fclose(arquivo);
    printf("Agenda salva com sucesso!\n");
}

void carregar_agenda(struct Contato lista_contatos[], int *total_contatos, char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }
    fread(total_contatos, sizeof(int), 1, arquivo);
    fread(lista_contatos, sizeof(struct Contato), *total_contatos, arquivo);
    fclose(arquivo);
    printf("Agenda carregada com sucesso!\n");
}