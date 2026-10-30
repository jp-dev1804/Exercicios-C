//Cadastro de uma pessoa

#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
    char endereco[100];
};

int main() {
    struct Pessoa p;

    printf("Nome: ");
    scanf(" %[^\n]", p.nome);

    printf("Idade: ");
    scanf("%d", &p.idade);

    printf("Endereco: ");
    scanf(" %[^\n]", p.endereco);

    printf("\nNome: %s", p.nome);
    printf("\nIdade: %d", p.idade);
    printf("\nEndereco: %s\n", p.endereco);

    return 0;
}