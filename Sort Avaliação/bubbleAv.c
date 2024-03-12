#include <stdio.h>

void bubbleSort(int arr[], int n) {
  int i, j, temp;
  int comparacoes = 0; 
  int trocas = 0;
  for(i = 0; i < n-1; i++){
    for(j = n-1; j > 0; j--){
      comparacoes++;
      if(arr[j] > arr[j-1]){
        temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = temp;
        trocas++;
      }
    }
  }
  printf("Comparacoes: %d, Trocas: %d\n", comparacoes, trocas);
}

int main() {
  int lista[9] = {6, 4, 7, 2, 8, 3, 9, 5, 1};
  bubbleSort(lista, 9);
  for(int i = 0; i < 9; i++){
    printf("%d ", lista[i]);
  }
  printf("\n");

  

  
  return 0;
}