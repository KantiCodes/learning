#include <stdio.h>
#include <stdlib.h>
#define N 5

void swap(int *a, int *b){
    *a = *b ^ *a; // b xor a
    *b = *a ^ *b; // b xor a xor b = a
    *a = *a ^*b; // b xor a xor a = b4

}

void bubbleSort(int *arr, int n) {
    if (n==1) {
        return;
    }

    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void printArray(int *arr, int n) {
    for (int i=0; i<n; i++) {
        printf("\t%d", arr[i]);
    }
    return;
}

int main() {
    int a[N] = {111,2,5,3,4};
    int *b = a;
    // printf("size of a: %lu\n", sizeof(a));
    // printf("size of b: %lu\n", sizeof(&b));
    // printf("size of: %lu\n", sizeof(a) / sizeof (a[0]));
    // // printf("Size of: %d\n", len(a));
    printArray(a, N);
    printf("\n");
    bubbleSort(a, N);
    printArray(a, N);


}