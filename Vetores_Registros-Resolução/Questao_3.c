#include <stdio.h>
#include <string.h>

#define MAX_CONTAS 100

typedef struct {
    int numero;
    char nome[80];
    char cpf[15];
    char telefone[20];
    double saldo;
} Conta;

typedef struct {
    Conta contas[MAX_CONTAS];
    int quantidade;
} Cadastro;

void limparEntrada(void) {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {}
}

/* Retorna -1 se vazio, -2 se nao encontrar e a posicao se encontrar. */
int buscarConta(Cadastro *cadastro, int numero) {
    int i;

    if (cadastro->quantidade == 0)
        return -1;

    for (i = 0; i < cadastro->quantidade; i++) {
        if (cadastro->contas[i].numero == numero)
            return i;
    }

    return -2;
}

/* Cadastra uma nova conta no final do vetor. */
void cadastrarConta(Cadastro *cadastro, int numero) {
    int resultado;

    if (cadastro->quantidade >= MAX_CONTAS) {
        printf("Cadastro cheio: limite de 100 contas.\n");
        return;
    }

    resultado = buscarConta(cadastro, numero);

    if (resultado >= 0) {
        printf("Numero de conta repetido. Cadastro nao realizado.\n");
        return;
    }

    cadastro->contas[cadastro->quantidade].numero = numero;

    limparEntrada();

    printf("Nome do titular: ");

    if (!fgets(cadastro->contas[cadastro->quantidade].nome,
               sizeof(cadastro->contas[cadastro->quantidade].nome), stdin))
        return;

    cadastro->contas[cadastro->quantidade].nome[
        strcspn(cadastro->contas[cadastro->quantidade].nome, "\n")] = '\0';

    printf("CPF: ");

    if (!fgets(cadastro->contas[cadastro->quantidade].cpf,
               sizeof(cadastro->contas[cadastro->quantidade].cpf), stdin))
        return;

    cadastro->contas[cadastro->quantidade].cpf[
        strcspn(cadastro->contas[cadastro->quantidade].cpf, "\n")] = '\0';

    printf("Telefone: ");

    if (!fgets(cadastro->contas[cadastro->quantidade].telefone,
               sizeof(cadastro->contas[cadastro->quantidade].telefone), stdin))
        return;

    cadastro->contas[cadastro->quantidade].telefone[
        strcspn(cadastro->contas[cadastro->quantidade].telefone, "\n")] = '\0';

    printf("Saldo inicial: ");

    if (scanf("%lf", &cadastro->contas[cadastro->quantidade].saldo) != 1) {
        limparEntrada();
        return;
    }

    if (cadastro->contas[cadastro->quantidade].saldo < 0) {
        printf("Saldo inicial nao pode ser negativo. Cadastro cancelado.\n");
        return;
    }

    cadastro->quantidade++;

    printf("Conta cadastrada com sucesso.\n");
}

/* Consulta o saldo de uma conta. */
void consultarSaldo(Cadastro *cadastro, int numero) {
    int pos = buscarConta(cadastro, numero);

    if (pos >= 0) {
        printf("Saldo da conta %d: R$ %.2f\n",
               numero, cadastro->contas[pos].saldo);
    } else {
        printf("Conta nao cadastrada.\n");
    }
}

/* Realiza deposito em uma conta existente. */
void depositar(Cadastro *cadastro, int numero) {
    int pos = buscarConta(cadastro, numero);
    double valor;

    if (pos < 0) {
        printf("Conta nao cadastrada.\n");
        return;
    }

    printf("Valor do deposito: ");

    if (scanf("%lf", &valor) != 1) {
        limparEntrada();
        return;
    }

    if (valor <= 0) {
        printf("O deposito deve ser maior que zero.\n");
        return;
    }

    cadastro->contas[pos].saldo += valor;

    printf("Deposito realizado. Novo saldo: R$ %.2f\n",
           cadastro->contas[pos].saldo);
}

/* Realiza saque se houver saldo suficiente. */
void sacar(Cadastro *cadastro, int numero) {
    int pos = buscarConta(cadastro, numero);
    double valor;

    if (pos < 0) {
        printf("Conta nao cadastrada.\n");
        return;
    }

    printf("Valor do saque: ");

    if (scanf("%lf", &valor) != 1) {
        limparEntrada();
        return;
    }

    if (valor <= 0) {
        printf("O saque deve ser maior que zero.\n");
        return;
    }

    if (valor > cadastro->contas[pos].saldo) {
        printf("Nao existe saldo suficiente.\n");
        return;
    }

    cadastro->contas[pos].saldo -= valor;

    printf("Saque realizado. Novo saldo: R$ %.2f\n",
           cadastro->contas[pos].saldo);
}

/* Exibe numero, titular e telefone de todas as contas. */
void listarContas(Cadastro *cadastro) {
    int i;

    if (cadastro->quantidade == 0) {
        printf("Cadastro vazio.\n");
        return;
    }

    printf("\n--- CONTAS CADASTRADAS ---\n");

    for (i = 0; i < cadastro->quantidade; i++) {
        printf("Conta: %d | Titular: %s | Telefone: %s\n",
               cadastro->contas[i].numero,
               cadastro->contas[i].nome,
               cadastro->contas[i].telefone);
    }
}

int main(void) {
    Cadastro corrente = { .quantidade = 0 };
    Cadastro poupanca = { .quantidade = 0 };

    int tipo, opcao, numero;
    Cadastro *cadastro;

    do {
        printf("\n===== BANCO DINHEIRO CERTO =====\n");
        printf("1 - Conta corrente\n");
        printf("2 - Conta poupanca\n");
        printf("0 - Sair\n");

        printf("Tipo de cadastro: ");

        if (scanf("%d", &tipo) != 1) {
            limparEntrada();
            break;
        }

        if (tipo == 0)
            break;

        if (tipo == 1) {
            cadastro = &corrente;
        } else if (tipo == 2) {
            cadastro = &poupanca;
        } else {
            printf("Tipo invalido.\n");
            continue;
        }

        do {
            printf("\n--- MENU %s ---\n",
                   tipo == 1 ? "CONTA CORRENTE" : "CONTA POUPANCA");

            printf("1 - Cadastrar conta\n");
            printf("2 - Consultar saldo\n");
            printf("3 - Depositar\n");
            printf("4 - Sacar\n");
            printf("5 - Listar contas\n");
            printf("0 - Voltar ao menu anterior\n");

            printf("Opcao: ");

            if (scanf("%d", &opcao) != 1) {
                limparEntrada();
                opcao = 0;
                break;
            }

            switch (opcao) {
                case 1:
                    printf("Numero da nova conta: ");
                    scanf("%d", &numero);

                    cadastrarConta(cadastro, numero);
                    break;

                case 2:
                    printf("Numero da conta: ");
                    scanf("%d", &numero);

                    consultarSaldo(cadastro, numero);
                    break;

                case 3:
                    printf("Numero da conta: ");
                    scanf("%d", &numero);

                    depositar(cadastro, numero);
                    break;

                case 4:
                    printf("Numero da conta: ");
                    scanf("%d", &numero);

                    sacar(cadastro, numero);
                    break;

                case 5:
                    listarContas(cadastro);
                    break;

                case 0:
                    break;

                default:
                    printf("Opcao invalida.\n");
            }

        } while (opcao != 0);

    } while (tipo != 0);

    printf("Encerrando o programa.\n");

    return 0;
}