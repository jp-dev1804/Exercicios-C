#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 40

typedef struct {
    int codigo;
    char descricao[80];
    double valorUnitario;
    int quantidadeEstoque;
} Produto;

void limparEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int buscarProduto(Produto produtos[], int quantidade, int codigo) {
    int i;

    for (i = 0; i < quantidade; i++) {
        if (produtos[i].codigo == codigo)
            return i;
    }

    return -1;
}

void cadastrarProduto(Produto produtos[], int *quantidade) {
    int codigo;

    if (*quantidade >= MAX_PRODUTOS) {
        printf("Cadastro cheio: limite de 40 produtos.\n");
        return;
    }

    printf("Codigo: ");
    if (scanf("%d", &codigo) != 1) {
        limparEntrada();
        return;
    }

    if (buscarProduto(produtos, *quantidade, codigo) != -1) {
        printf("Ja existe produto com esse codigo.\n");
        return;
    }

    produtos[*quantidade].codigo = codigo;

    limparEntrada();

    printf("Descricao: ");
    if (!fgets(produtos[*quantidade].descricao,
               sizeof(produtos[*quantidade].descricao), stdin))
        return;

    produtos[*quantidade].descricao[
        strcspn(produtos[*quantidade].descricao, "\n")] = '\0';

    printf("Valor unitario: ");
    if (scanf("%lf", &produtos[*quantidade].valorUnitario) != 1) {
        limparEntrada();
        return;
    }

    printf("Quantidade em estoque: ");
    if (scanf("%d", &produtos[*quantidade].quantidadeEstoque) != 1) {
        limparEntrada();
        return;
    }

    if (produtos[*quantidade].valorUnitario < 0 ||
        produtos[*quantidade].quantidadeEstoque < 0) {
        printf("Valor e quantidade nao podem ser negativos.\n");
        return;
    }

    (*quantidade)++;

    printf("Produto cadastrado com sucesso.\n");
}

void alterarValorUnitario(Produto produtos[], int quantidade, int codigo) {
    int pos = buscarProduto(produtos, quantidade, codigo);
    double novoValor;

    if (pos == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("Novo valor unitario: ");
    if (scanf("%lf", &novoValor) != 1) {
        limparEntrada();
        return;
    }

    if (novoValor < 0) {
        printf("O valor nao pode ser negativo.\n");
        return;
    }

    produtos[pos].valorUnitario = novoValor;

    printf("Valor unitario atualizado.\n");
}

double consultarValorUnitario(Produto produtos[], int quantidade, int codigo) {
    int pos = buscarProduto(produtos, quantidade, codigo);

    if (pos == -1)
        return -1.0;

    return produtos[pos].valorUnitario;
}

int consultarQuantidadeEstoque(Produto produtos[], int quantidade, int codigo) {
    int pos = buscarProduto(produtos, quantidade, codigo);

    if (pos == -1)
        return -1;

    return produtos[pos].quantidadeEstoque;
}

void realizarVenda(Produto produtos[], int quantidade, int codigo, int desejada) {
    int pos = buscarProduto(produtos, quantidade, codigo);
    int vender;
    char resposta;

    if (pos == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    if (produtos[pos].quantidadeEstoque == 0) {
        printf("Produto com estoque zero.\n");
        return;
    }

    if (desejada <= 0) {
        printf("Quantidade desejada deve ser positiva.\n");
        return;
    }

    if (desejada <= produtos[pos].quantidadeEstoque) {
        vender = desejada;
    } else {
        printf("Estoque disponivel: %d. Deseja comprar toda a quantidade disponivel? (S/N): ",
               produtos[pos].quantidadeEstoque);

        if (scanf(" %c", &resposta) != 1)
            return;

        if (resposta != 'S' && resposta != 's') {
            printf("Venda cancelada.\n");
            return;
        }

        vender = produtos[pos].quantidadeEstoque;
    }

    produtos[pos].quantidadeEstoque -= vender;

    printf("Venda realizada. Quantidade: %d | Total a pagar: R$ %.2f\n",
           vender, vender * produtos[pos].valorUnitario);
}

void atualizarEstoque(Produto produtos[], int quantidade, int codigo) {
    int pos, novaQuantidade;

    pos = buscarProduto(produtos, quantidade, codigo);

    if (pos == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("Quantidade a acrescentar ao estoque: ");

    if (scanf("%d", &novaQuantidade) != 1) {
        limparEntrada();
        return;
    }

    if (novaQuantidade < 0) {
        printf("Quantidade nao pode ser negativa.\n");
        return;
    }

    produtos[pos].quantidadeEstoque += novaQuantidade;

    printf("Estoque atualizado: %d unidade(s).\n",
           produtos[pos].quantidadeEstoque);
}

void listarProdutos(Produto produtos[], int quantidade) {
    int i;

    if (quantidade == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\n--- TODOS OS PRODUTOS ---\n");

    for (i = 0; i < quantidade; i++) {
        printf("Codigo: %d | Descricao: %s\n",
               produtos[i].codigo, produtos[i].descricao);
    }
}

void listarProdutosSemEstoque(Produto produtos[], int quantidade) {
    int i, encontrou = 0;

    printf("\n--- PRODUTOS COM ESTOQUE ZERO ---\n");

    for (i = 0; i < quantidade; i++) {
        if (produtos[i].quantidadeEstoque == 0) {
            printf("Codigo: %d | Descricao: %s\n",
                   produtos[i].codigo, produtos[i].descricao);

            encontrou = 1;
        }
    }

    if (!encontrou)
        printf("Nenhum produto com estoque zero.\n");
}

int main(void) {
    Produto produtos[MAX_PRODUTOS];

    int quantidade = 0;
    int opcao, codigo, qtd;
    double valor;

    do {
        printf("\n===== PAPELARIA ESCOLAR =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Alterar valor unitario\n");
        printf("3 - Consultar valor unitario\n");
        printf("4 - Consultar quantidade em estoque\n");
        printf("5 - Realizar venda\n");
        printf("6 - Atualizar estoque (reposicao)\n");
        printf("7 - Exibir todos os produtos\n");
        printf("8 - Exibir produtos com estoque zero\n");
        printf("0 - Sair\n");

        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            limparEntrada();
            break;
        }

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &quantidade);
                break;

            case 2:
                printf("Codigo do produto: ");
                scanf("%d", &codigo);

                alterarValorUnitario(produtos, quantidade, codigo);
                break;

            case 3:
                printf("Codigo do produto: ");
                scanf("%d", &codigo);

                valor = consultarValorUnitario(produtos, quantidade, codigo);

                if (valor < 0)
                    printf("Produto nao encontrado.\n");
                else
                    printf("Valor unitario: R$ %.2f\n", valor);

                break;

            case 4:
                printf("Codigo do produto: ");
                scanf("%d", &codigo);

                qtd = consultarQuantidadeEstoque(produtos, quantidade, codigo);

                if (qtd < 0)
                    printf("Produto nao encontrado.\n");
                else
                    printf("Quantidade em estoque: %d\n", qtd);

                break;

            case 5:
                printf("Codigo do produto: ");
                scanf("%d", &codigo);

                printf("Quantidade desejada: ");
                scanf("%d", &qtd);

                realizarVenda(produtos, quantidade, codigo, qtd);
                break;

            case 6:
                printf("Codigo do produto: ");
                scanf("%d", &codigo);

                atualizarEstoque(produtos, quantidade, codigo);
                break;

            case 7:
                listarProdutos(produtos, quantidade);
                break;

            case 8:
                listarProdutosSemEstoque(produtos, quantidade);
                break;

            case 0:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}