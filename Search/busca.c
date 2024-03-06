#include <stdio.h>
#include <stdlib.h>

// Questão 1


int atualizacao(int tamanho, int vetor[], int valor_busca, int novo_valor) {
    for (int i = tamanho; i > 0; i--) {
        if (vetor[i] == valor_busca) {
            vetor[i] = novo_valor;

            return vetor[i]; 
        }
    }
    return -1;// Elemento não encontrado
}

int main() {
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int valor;
    int tamanho = sizeof(vetor);
    printf("Digite um valor: ");
    scanf("%d", &valor);
    int atualizado = atualizacao(tamanho, vetor, valor, 7);
    for(int i = 0; i < 10; i++) {
        printf("%d\n", vetor[i]);
    }
    if (atualizado != -1) {
        printf("O valor %d foi substituido por %d\n", valor, atualizado);
    } else {
        printf("O valor %d nao foi encontrado\n", valor);
    }
    return 0;
}