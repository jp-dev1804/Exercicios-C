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
    return novoTam
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
        v[i] = maior
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