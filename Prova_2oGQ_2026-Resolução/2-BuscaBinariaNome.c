#include <stdio.h>
#include <string.h>

#define TAM_CONTAS 50

struct Conta {
    int id;
    char cliente[40];
    double saldo;
    double limite;
};

// QUESTAO 2
int buscaBinariaNome(struct Conta v[], int tam, char x[]) {

    int inicio = 0;
    int fim = tam - 1;
    int meio;

    while (inicio <= fim) {

        meio = (inicio + fim) / 2;

        if (strcmp(v[meio].cliente, x) == 0) {
            return meio;
        }

        if (strcmp(v[meio].cliente, x) < 0) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return -1;
}

// TESTE
int main() {

    struct Conta contas[5] = {
        {1, "Ana", 1000, 500},
        {2, "Bruno", 2000, 500},
        {3, "Carlos", 1500, 300},
        {4, "Maria", 3000, 700},
        {5, "Pedro", 2500, 600}
    };

    char nome[40];
    int pos;

    printf("Digite o nome do cliente: ");
    scanf(" %39[^\n]", nome);

    pos = buscaBinariaNome(contas, 5, nome);

    if (pos != -1) {
        printf("\nCliente encontrado!\n");
        printf("Posicao: %d\n", pos);
        printf("ID: %d\n", contas[pos].id);
        printf("Nome: %s\n", contas[pos].cliente);
    }
    else {
        printf("Cliente nao encontrado!\n");
    }

    return 0;
}