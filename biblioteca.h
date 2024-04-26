#ifndef PROJETO3_BIBLIOTECA_H
#define PROJETO3_BIBLIOTECA_H

struct Contato {
    char nome[50];
    char sobrenome[50];
    char email[100];
    char telefone[15];
};

void adicionar_contato(struct Contato lista_contatos[], int *total_contatos);
void listar_contatos(struct Contato lista_contatos[], int total_contatos);
void deletar_contato(struct Contato lista_contatos[], int *total_contatos, char telefone[]);
void salvar_agenda(struct Contato lista_contatos[], int total_contatos, char *nome_arquivo);
void carregar_agenda(struct Contato lista_contatos[], int *total_contatos, char *nome_arquivo);

#endif