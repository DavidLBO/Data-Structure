#include <stdio.h>
#include <stdlib.h>

int buscaProximo(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho-1, meio;
    int proximo = vetor[inicio];
    
    while (inicio <= fim) {
        
        meio = (inicio + fim) / 2;

        if(vetor[meio] == valor) {
            return vetor[meio];
        } else if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }

         if (abs(vetor[meio] - valor) < abs(proximo - valor)) {
            proximo = vetor[meio];
        }
        
    }
    return proximo; // Elemento não encontrado
}

int main() {
    int vetorA[7] = {2, 5, 6, 7, 8, 8, 9};
    int vetorB[8] = {2, 3, 5, 6, 7, 8, 8, 9};
    int valor;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    int resultado = buscaProximo(vetorA, 7, valor);
    printf("Vetor A: %d\n", resultado);
    resultado = buscaProximo(vetorB, 8, valor);
    printf("Vetor B: %d\n", resultado);

    return 0;
}