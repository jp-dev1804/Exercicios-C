#include <stdio.h>
#include <string.h>

#define TAM_CONTAS 50
#define TAM_OPERACOES 10000

struct Conta {
    int id;
    char cliente[40];
    double saldo;
    double limite;
};

struct Operacao {
    int id;
    int idConta;
    char tipo;
    double valor;
};

// Funcao auxiliar
int buscId(struct Conta v[], int tam, int x) {

    int i;

    for (i = 0; i < tam; i++) {

        if (v[i].id == x) {
            return i;
        }
    }

    return -1;
}

// QUESTAO 5
void extrato(struct Conta vContas[], int tamConta,
             struct Operacao vOp[], int *tamOp) {

    int id, pos, i, j;
    int ultimas[5];
    int qtd = 0;

    double saldo, saldoAnterior;

    char *tipo;

    printf("Digite o ID da conta: ");
    scanf("%d", &id);

    pos = buscId(vContas, tamConta, id);

    if (pos == -1) {
        printf("Conta nao encontrada!\n");
        return;
    }

    for (i = 0; i < *tamOp; i++) {

        if (vOp[i].idConta == id) {

            if (qtd < 5) {
                ultimas[qtd] = i;
                qtd++;
            }
            else {

                for (j = 0; j < 4; j++) {
                    ultimas[j] = ultimas[j + 1];
                }

                ultimas[4] = i;
            }
        }
    }

    if (qtd == 0) {
        printf("Nenhuma operacao encontrada!\n");
        return;
    }

    printf("\nCONTA: %d\n", vContas[pos].id);
    printf("CLIENTE: %s\n", vContas[pos].cliente);

    saldoAnterior = 0;

    for (j = 0; j < ultimas[0]; j++) {

        if (vOp[j].idConta == id) {
            saldoAnterior += vOp[j].valor;
        }
    }

    printf("\nSaldo Anterior: %.2lf\n", saldoAnterior);

    for (i = 0; i < qtd; i++) {

        int indice = ultimas[i];

        saldo = 0;

        for (j = 0; j < indice; j++) {

            if (vOp[j].idConta == id) {
                saldo += vOp[j].valor;
            }
        }

        saldoAnterior = saldo;

        saldo = saldoAnterior + vOp[indice].valor;

        if (vOp[indice].tipo == 'D') {
            tipo = "Deposito";
        }
        else if (vOp[indice].tipo == 'S') {
            tipo = "Saque";
        }
        else {
            tipo = "Transferencia";
        }

        printf("%04d | %s | ", vOp[indice].id, tipo);

        if (vOp[indice].valor >= 0) {
            printf("%.2lfC | ", vOp[indice].valor);
        }
        else {
            printf("%.2lfD | ", -vOp[indice].valor);
        }

        printf("%.2lf\n", saldo);
    }

    printf("\nSaldo Atual: %.2lf\n", vContas[pos].saldo);
}

// TESTE
int main() {

    struct Conta contas[1] = {
        {1, "Maria Jose Santos", 424.99, 500}
    };

    struct Operacao operacoes[6] = {

        {10, 1, 'D', 2437.55},
        {25, 1, 'D', 1000.00},
        {37, 1, 'D', 237.44},
        {83, 1, 'T', -4000.00},
        {95, 1, 'S', -250.00},
        {112, 1, 'T', 1000.00}

    };

    int tamOp = 6;

    extrato(contas, 1, operacoes, &tamOp);

    return 0;
}