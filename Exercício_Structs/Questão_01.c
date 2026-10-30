//Criação de novos tipos de dados

#include <stdio.h>

struct Horario {
    int hora, minutos, segundos;
};

struct Data {
    int dia, mes, ano;
};

struct Compromisso {
    struct Data data;
    struct Horario horario;
    char descricao[100];
};

int main() {
    struct Compromisso c;

    printf("Digite a data (dia mes ano): ");
    scanf("%d %d %d", &c.data.dia, &c.data.mes, &c.data.ano);

    printf("Digite o horario (hora minutos segundos): ");
    scanf("%d %d %d", &c.horario.hora, &c.horario.minutos, &c.horario.segundos);

    printf("Digite a descricao: ");
    scanf(" %[^\n]", c.descricao);

    printf("\nData: %02d/%02d/%d", c.data.dia, c.data.mes, c.data.ano);
    printf("\nHorario: %02d:%02d:%02d", c.horario.hora, c.horario.minutos, c.horario.segundos);
    printf("\nCompromisso: %s\n", c.descricao);

    return 0;
}