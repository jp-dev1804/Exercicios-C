#include <stdio.h>

#define QTD_COLUNAS 3

//a)
int removerRepetidos(int v[], int tam) {
    int novoTam = 1;
    int i;

    for(i = 1; i < tam; i++) {
        if(v[i] != v[novoTam - 1]) {
            v[novoTam] = v[i];
            novoTam++;
        }
    }
    return novoTam;
}

//b)
void ordenar(int v[], int tam) {
    int i, j, aux;
    for(i = 0; i < tam - 1; i++){
        for(j = 0; j < tam - 1 - i; j++) {
            if(v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

//c)
int ehPrimo(int numero, int v[], int qtd) {
    int i;
    for(i = 0; i < qtd; i++) {
        if(numero % v[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void preencherPrimos(int v[], int tam) {
    int numero = 2;
    int qtd = 0;

    while(qtd < tam) {
        if(ehPrimo(numero, v, qtd)) {
            v[qtd] = numero;
            qtd++;
        }
        numero++;
    }
}

//d)
void maiorPorLinha(int m[][QTD_COLUNAS], int lin, int col, int v[]) {
    int i, j;
    int maior;
    
    for(i = 0; i < lin; i++) {
        maior = m[i][0];
        for(j = 1; j < col; j++) {
            if(m[i][j] > maior) {
                maior = m[i][j];
            }
        }
        v[i] = maior;
    }
}

//e)
void inverter(char str[], int inicio, int fim) {
    char aux;
    while(inicio < fim) {
        aux = str[inicio];
        str[inicio] = str[fim];
        str[fim] = aux;

        inicio++;
        fim--;
    }
}

void inverterPalavras(char str[]) {
    int i = 0;
    int inicio;
    while(str[i] != '\0') {
        if(str[i] != ' ') {
            inicio = i;
            while(str[i] != ' ' && str[i] != '\0') {
                i++;
            }
            inverter(str, inicio, i - 1);
        } else {
            i++;
        }
    }
}

//MAIN
int main()
{
    int tam;
    int i;

    // ===== A =====

    printf("Digite o tamanho do vetor A: ");
    scanf("%d", &tam);

    int vA[tam];

    printf("Digite os valores em ordem crescente:\n");

    for (i = 0; i < tam; i++)
    {
        scanf("%d", &vA[i]);
    }

    int novoTam = removerRepetidos(vA, tam);

    printf("A - Vetor sem repetidos: ");

    for (i = 0; i < novoTam; i++)
    {
        printf("%d ", vA[i]);
    }

    printf("\nNovo tamanho: %d\n\n", novoTam);


    // ===== B =====

    printf("Digite o tamanho do vetor B: ");
    scanf("%d", &tam);

    int vB[tam];

    printf("Digite os valores:\n");

    for (i = 0; i < tam; i++)
    {
        scanf("%d", &vB[i]);
    }

    ordenar(vB, tam);

    printf("B - Vetor ordenado: ");

    for (i = 0; i < tam; i++)
    {
        printf("%d ", vB[i]);
    }

    printf("\n\n");


    // ===== C =====

    printf("Digite o tamanho do vetor C: ");
    scanf("%d", &tam);

    int vC[tam];

    preencherPrimos(vC, tam);

    printf("C - Numeros primos: ");

    for (i = 0; i < tam; i++)
    {
        printf("%d ", vC[i]);
    }

    printf("\n\n");


    // ===== D =====

    int lin;
    int col;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &lin);

    printf("Digite o numero de colunas (maximo %d): ", QTD_COLUNAS);
    scanf("%d", &col);

    int matriz[lin][QTD_COLUNAS];
    int vD[lin];

    printf("Digite os valores da matriz:\n");

    for (i = 0; i < lin; i++)
    {
        int j;

        for (j = 0; j < col; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    maiorPorLinha(matriz, lin, col, vD);

    printf("D - Maior de cada linha: ");

    for (i = 0; i < lin; i++)
    {
        printf("%d ", vD[i]);
    }

    printf("\n\n");


    // ===== E =====

    char str[100];

    printf("Digite uma frase: ");
    scanf(" %[^\n]", str);

    inverterPalavras(str);

    printf("E - Frase invertida: %s\n", str);


    return 0;
}