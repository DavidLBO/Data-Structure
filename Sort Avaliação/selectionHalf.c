#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int i, j, max, min, temp;
    int passagem = 0;

    for (i = 0; i < n / 2; i++) {
        max = i;
        min = i;
        for (j = i + 1; j < n - i; j++)
        {
            if (arr[j] > arr[max])
            {
                max = j;
            } 
            if (arr[j] < arr[min]) {
                min = j;
            }
            
        }
        if (arr[i] > arr[min])
            {
                temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
            if(max == i){
                max = min;
            }
            if (arr[n-i-1] < arr[max])
            {
                temp = arr[n-i-1];
                arr[n-i-1] = arr[max];
                arr[max] = temp;
            }
        
        passagem++;
        printf("Passagens: %d\n", passagem);
    }
}

int main()
{
    int lista[9] = {6, 4, 7, 2, 8, 3, 9, 5, 1};
    selectionSort(lista, 9);
    printf("Array ordenado: ");
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", lista[i]);
    }
    printf("\n");

    return 0;
}