#include <stdio.h>
#include <stdlib.h>

// Questão 3

int buscaSequencial(int tamanho, int vetor[], int valor) {
    for (int i = 0; i < tamanho-1; i++) {
        for (int j = tamanho-1; j > i; j-- ) {
            printf("Valor pela esquerda: %d; Valor pela direita: %d\n", vetor[i], vetor[j]);
            if (vetor[i] == valor) {
                return i;
            }
            if (vetor[j] == valor) {
                return j;
            }
            i++;
        }
    }
    
    
    return -1; // Elemento não encontrado
}

int main() {
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, valor;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    int posicao = buscaSequencial(10, vetor, valor);
    if (posicao != -1) {
        printf("O valor %d foi encontrado na posicao %d\n", valor, posicao);
    } else {
        printf("O valor %d nao foi encontrado\n", valor);
    }
    return 0;
}