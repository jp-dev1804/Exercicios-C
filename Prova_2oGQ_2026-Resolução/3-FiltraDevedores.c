#include <stdio.h>
#include <string.h>

#define TAM_CONTAS 50

struct Conta {
    int id;
    char cliente[40];
    double saldo;
    double limite;
};

// QUESTAO 3
void filtraDevedores(struct Conta vContas[], int tamConta,
                     struct Conta vDevedores[], int *tamDevedores) {

    int i;

    *tamDevedores = 0;

    for (i = 0; i < tamConta; i++) {

        if (vContas[i].saldo < 0) {

            vDevedores[*tamDevedores] = vContas[i];

            (*tamDevedores)++;
        }
    }
}

// TESTE
int main() {

    struct Conta contas[5] = {
        {1, "Ana", 1000, 500},
        {2, "Bruno", -200, 500},
        {3, "Carlos", 1500, 300},
        {4, "Maria", -100, 700},
        {5, "Pedro", -300, 600}
    };

    struct Conta devedores[TAM_CONTAS];

    int tamDevedores = 0;
    int i;

    filtraDevedores(contas, 5, devedores, &tamDevedores);

    printf("--- CONTAS DEVEDORAS ---\n");

    for (i = 0; i < tamDevedores; i++) {

        printf("\nID: %d\n", devedores[i].id);
        printf("Cliente: %s\n", devedores[i].cliente);
        printf("Saldo: %.2lf\n", devedores[i].saldo);
    }

    printf("\nTotal de devedores: %d\n", tamDevedores);

    return 0;
}