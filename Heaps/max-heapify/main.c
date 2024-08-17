#include <stdio.h>

int left(int i) {
    return 2*i + 1;  
}

int right(int i) {
    return 2*i + 2; 
}

void max_heapify(int *array, int i, int size) {
    int l = left(i);
    int r = right(i);
    int largest;

    if (l < size && array[l] > array[i])
        largest = l;
    else
        largest = i;

    if (r <= size && array[r] > array[largest]) 
        largest = r;
    
    if (largest != i) {
        int aux = array[i];
        array[i] = array[largest];
        array[largest] = aux;
        max_heapify(array, largest, size);
    }
}

int main() {

    int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};   

    int size1 = sizeof(array) / sizeof(array[0]);   //tamanho do array
    printf("array size -> %d\n", size1);
    max_heapify(array, 0, size1);
    for(int i = 0; i < size1; i++) 
        printf("%d, ", array[i]);
    
    return 0;
}