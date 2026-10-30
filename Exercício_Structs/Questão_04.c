//Conversão de coordenadas polares para cartesianas

#include <stdio.h>
#include <math.h>

struct Polar {
    double r;
    double a;
};

struct Cartesiana {
    double x;
    double y;
};

int main() {
    struct Polar p;
    struct Cartesiana c;

    printf("Digite o raio e o angulo em radianos: ");
    scanf("%lf %lf", &p.r, &p.a);

    c.x = p.r * cos(p.a);
    c.y = p.r * sin(p.a);

    printf("\nCoordenadas cartesianas:");
    printf("\nx = %.2lf", c.x);
    printf("\ny = %.2lf\n", c.y);

    return 0;
}