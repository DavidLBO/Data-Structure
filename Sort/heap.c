#include <stdio.h>

void ajustarHeap(int n, int arr[n], int i){
    int menor = i;
    int left, right, temp;
    while (menor < n){
        left =  2 * i + 1;
        right =  2 * i + 2;

        if(left < n && arr[left] < arr[menor]){
            menor = left;
        }
        if(right < n && arr[right] < arr[menor]){
            menor = right;
        }
        if(menor != i){
            temp = arr[i];
            arr[i] = arr[menor];
            arr[menor] = temp;
            i = menor;  
        } else {
            break;
        }
        for(int i = 0; i < 9; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void construirHeap(int n, int arr[n]) {
    int i;
    for(i = n/2-1; i >= 0; i--){
        ajustarHeap(n, arr, i);
    }
}

void ordenarHeap(int n, int arr[n]){
    int i, temp;
    construirHeap(n, arr);
    for(i = n-1; i > 0; i--){
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        ajustarHeap(i, arr, 0);

    }
}

int main() {
    int lista[9] = {6, 4, 7, 2, 8, 3, 9, 5, 1};
    ordenarHeap(9, lista);
    printf("Versao final: \n");
    for(int i = 0; i < 9; i++){
      printf("%d ", lista[i]);
    }
    printf("\n");

    return 0;
}
