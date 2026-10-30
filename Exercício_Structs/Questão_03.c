//Soma de dois vetores

#include <stdio.h>

struct Vetor {
    double x;
    double y;
    double z;
};

int main() {
    struct Vetor a, b, soma;

    printf("Digite o primeiro vetor (x y z): ");
    scanf("%lf %lf %lf", &a.x, &a.y, &a.z);

    printf("Digite o segundo vetor (x y z): ");
    scanf("%lf %lf %lf", &b.x, &b.y, &b.z);

    soma.x = a.x + b.x;
    soma.y = a.y + b.y;
    soma.z = a.z + b.z;

    printf("\nVetor soma: (%.2lf, %.2lf, %.2lf)\n", soma.x, soma.y, soma.z);

    return 0;
}