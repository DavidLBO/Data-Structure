  #include <stdio.h>
  
  void selectionSort(int arr[], int n) {
    int i, j, max, temp;
    int comparacoes = 0; 
    int trocas = 0;

    for(i = n-1; i > 0; i--){
      max = i;
      for(j = 0; j < i; j++){
        if(arr[j] > arr[max]){
          max = j;
        }
        comparacoes++;
      }
      if(max != i){
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        trocas++;
      }
      
    }
      printf("Comparacoes: %d, Trocas: %d\n", comparacoes, trocas);
  }
  
  int main() {
    int lista[9] = {6, 4, 7, 2, 8, 3, 9, 5, 1};
    selectionSort(lista, 9);
    for(int i = 0; i < 9; i++){
      printf("%d ", lista[i]);
    }
    printf("\n");
  
  
  
  
    return 0;
  }