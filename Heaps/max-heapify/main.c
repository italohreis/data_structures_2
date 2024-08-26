#include <stdio.h>

int left(int i) {
    return 2*i +1;
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

    if (r < size && array[r] > array[largest]) 
        largest = r;
    
    if (largest != i) {
        int aux = array[i];
        array[i] = array[largest];
        array[largest] = aux;
        max_heapify(array, largest, size);
    }
}

int main() {

    int array[10] = {4,1,3,2,16,9,10,14,8,7};   

    int size1 = sizeof(array) / sizeof(array[0]);   //tamanho do array
    printf("array size -> %d\n", size1);
    
    int i;
    for (i = size1/2 - 1; i >= 0; i--) {
        max_heapify(array, i, size1);
    }

    int j;
    for(j = 0;j < size1; j++) {
        printf("%d, ", array[j]);
    }
    
    return 0;
}