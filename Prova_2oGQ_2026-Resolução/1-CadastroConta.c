#include <stdio.h>
#include <string.h>

#define TAM_CONTAS 50

struct Conta {
    int id;
    char cliente[40];
    double saldo;
    double limite;
};

// Funcao auxiliar para procurar ID
int buscId(struct Conta v[], int tam, int x) {
    int i;

    for (i = 0; i < tam; i++) {
        if (v[i].id == x) {
            return i;
        }
    }

    return -1;
}

// QUESTAO 1
void cadastraConta(struct Conta v[], int *tam) {

    int id;

    if (*tam >= TAM_CONTAS) {
        printf("Vetor cheio!\n");
        return;
    }

    printf("Digite o ID: ");
    scanf("%d", &id);

    if (buscId(v, *tam, id) != -1) {
        printf("ID ja cadastrado!\n");
        return;
    }

    v[*tam].id = id;

    printf("Digite o nome do cliente: ");
    scanf(" %39[^\n]", v[*tam].cliente);

    printf("Digite o saldo: ");
    scanf("%lf", &v[*tam].saldo);

    printf("Digite o limite: ");
    scanf("%lf", &v[*tam].limite);

    if (v[*tam].limite < 0) {
        printf("Limite invalido!\n");
        return;
    }

    (*tam)++;

    printf("Conta cadastrada com sucesso!\n");
}

// TESTE
int main() {

    struct Conta contas[TAM_CONTAS];
    int tam = 0;

    cadastraConta(contas, &tam);

    printf("\n--- CONTA CADASTRADA ---\n");

    if (tam > 0) {
        printf("ID: %d\n", contas[0].id);
        printf("Cliente: %s\n", contas[0].cliente);
        printf("Saldo: %.2lf\n", contas[0].saldo);
        printf("Limite: %.2lf\n", contas[0].limite);
    }

    return 0;
}