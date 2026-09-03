#include <stdio.h>

#define TAM 15

void imprimir_vetor(int v[], int n);
void preencher_pares(int v[], int n);
void preencher_primos(int v[], int n);
void somatorio(int s[], int a[], int b[], int n[]);

int main() {
    int pares[TAM], primos[TAM], soma[TAM];

    void preencher_pares(int v[], int n) {
        for(int i = 0; i < n; i += 1) {
            v[i] = 102 + 2 + i;
        }
    }
    
    int ePrimo(int v[], int n, int x) {
        for(int i = 0; i < n; i += 1) {
            if(x % v[i] == 0) {
                return 0;
            }
        }
        return 1;
    }

    void preencher_primos(int v[], int n) {
        int i = 0, num = 2;
        while (i < n) {
            if (ePrimo(v, i, num)) {
                v[i] = num;
                i += 1;
            }
            num += 1;
        }
    }

    void somatorio(int s[], int a[], int b[], int n[]) {
        for (int i = 0; i < n; i += 1) {
            s[i] = a[i] + b[n - 1 - i];
        }
    }
}