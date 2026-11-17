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

// QUESTAO 4
int realizarSaque(struct Conta vContas[], int tamConta,
                  struct Operacao vOp[], int *tamOp) {

    int id;
    int pos;
    double valor;

    printf("Digite o ID da conta: ");
    scanf("%d", &id);

    printf("Digite o valor do saque: ");
    scanf("%lf", &valor);

    pos = buscId(vContas, tamConta, id);

    if (pos == -1) {
        printf("Conta nao encontrada!\n");
        return 0;
    }

    if (valor <= 0) {
        printf("Valor invalido!\n");
        return 0;
    }

    if (*tamOp >= TAM_OPERACOES) {
        printf("Vetor de operacoes cheio!\n");
        return 0;
    }

    if (vContas[pos].saldo + vContas[pos].limite < valor) {
        printf("Saldo insuficiente!\n");
        return 0;
    }

    vContas[pos].saldo -= valor;

    vOp[*tamOp].id = *tamOp + 1;
    vOp[*tamOp].idConta = id;
    vOp[*tamOp].tipo = 'S';
    vOp[*tamOp].valor = -valor;

    (*tamOp)++;

    return 1;
}

// TESTE
int main() {

    struct Conta contas[1] = {
        {101, "Maria", 500, 200}
    };

    struct Operacao operacoes[TAM_OPERACOES];

    int tamOp = 0;
    int resultado;

    resultado = realizarSaque(contas, 1, operacoes, &tamOp);

    if (resultado == 1) {

        printf("\n--- SAQUE REALIZADO ---\n");

        printf("Cliente: %s\n", contas[0].cliente);
        printf("Novo saldo: %.2lf\n", contas[0].saldo);

        printf("ID da operacao: %d\n", operacoes[0].id);
        printf("Tipo: %c\n", operacoes[0].tipo);
        printf("Valor: %.2lf\n", operacoes[0].valor);
    }

    return 0;
}