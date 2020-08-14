#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 40000
#define VERDADEIRO 1
#define FALSO 0
void selecao(int *vetor){
    int i, j, iMenorValor;
    int auxValor;
    for (i = 0; i < TAMANHO -1; i++){
        iMenorValor = i;
        for (j = i + 1; j < TAMANHO; j++){
            if (vetor[j] < vetor[i]){
                iMenorValor = j;
                auxValor = vetor[iMenorValor];
                vetor[iMenorValor] = vetor[i];
                vetor[i] = auxValor;
            }
        }
    }
}

void insercao(int *vetor){
    int i, k, aux;
    for (k = 1; k < TAMANHO; k++)
        {
        aux = vetor[k];
        for (i = k - 1; i >= 0 && aux < vetor[i]; i--)
        {
            vetor[i + 1] = vetor[i];
        }
        vetor[i + 1] = aux;
    }
}

void bolha(int *vetor){
    int i, j, aux;
    int troca = VERDADEIRO;
    for (i = 0; i < TAMANHO && troca == VERDADEIRO; i++){
        troca = FALSO;
        for (j = 0; j < TAMANHO - 1; j++){
            if (vetor[j] > vetor[j + 1]){
                troca = VERDADEIRO;
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int particao(int primeiro, int ultimo, int *vetor){
    int i, j = ultimo;
    int aux, pivo;
    pivo = vetor[primeiro];
    for (i = ultimo; i >= primeiro; i--){
        if (vetor[i] >= pivo){
            aux = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = aux;
            j--;
        }
    }
    return j + 1;
}

void quickSort(int primeiro, int ultimo, int *vetor){
    int x;
    if (primeiro < ultimo){
        x = particao(primeiro, ultimo, vetor);
        quickSort(primeiro, x - 1, vetor);
        quickSort(x + 1, ultimo, vetor);
    }
}

void merge(int *a, int inicio, int meio, int fim){
    int n, *b, i1, i2, j;
    j = 0;
    n = fim - inicio + 1;
    b = (int*) malloc(n * sizeof(int));
    i1 = inicio;
    i2 = meio + 1;
    while ((i1 <= meio) && (i2 <= fim)){
        if (a[i1] < a[i2]){
            b[j] = a[i1];
            i1++;
        }
        else{
            b[j] = a[i2];
            i2++;
        }
        j++;
    }
    while (i1 <= meio){
        b[j] = a[i1];
        i1++;
        j++;
    }
    while (i2 <= fim){
        b[j] = a[i2];
        i2++;
        j++;
    }
    for (j = 0; j <= n - 1; j++){
        a[inicio + j] = b[j];
    }
}

void mergeSort(int *a, int inicio, int fim){
    int meio;
    if (inicio == fim){
        return;
    meio = (inicio + fim)/2;
    mergeSort(a, inicio, meio);
    mergeSort(a, meio + 1, fim);
    merge(a, inicio, meio, fim);
    }
}

void printVetor(int *vetor){
    int i;
 for (i = 0; i < TAMANHO; i++){
        printf("%d\n", vetor[i]);
    }
}

int main(){
    int vetorPrincipal[TAMANHO];
    int v1 = vetorPrincipal;
    int v2 = vetorPrincipal;
    int v3 = vetorPrincipal;
    int v4 = vetorPrincipal;
    int v5 = vetorPrincipal;
    double Tempo;
    int i;
    for (i = 0; i < TAMANHO; i ++){
        vetorPrincipal[i] = rand() % TAMANHO;
    }
    clock_t Ticks[2];
    Ticks[0] = clock();
    selecao(v1);
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]);
    printf("Tempo gasto para selecao: %g\n", Tempo);

    Ticks[0] = clock();
    insercao(v2);
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]);
    printf("Tempo gasto para insercao: %g\n", Tempo);

    Ticks[0] = clock();
    bolha(v3);
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]);
    printf("Tempo gasto para bolha: %g\n", Tempo);

    Ticks[0] = clock();
    quickSort(0, TAMANHO, v4);
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]);
    printf("Tempo gasto para quickSort: %g\n", Tempo);

    Ticks[0] = clock();
    mergeSort(v5 ,0 , TAMANHO);
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]);
    printf("Tempo gasto para mergeSort: %g\n", Tempo);
}
