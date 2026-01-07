#include <stdlib.h>
#include <stdio.h>
#include "commons.h"

#define N 6

int main() {
    const int n = N;
    int arr[N] = {1,2,3,4,5,6};
    printArray(arr, n);
    printf("\n");
    int *first = malloc(sizeof(int) * N/2);
    int *second = malloc(sizeof(int) * N/2);
    
    if (!first | !second){
        fprintf(stderr, "Error: malloc failed\n");
    }
    
    int *arrz = malloc(1024L * 1024 * 1024 * 1024); // trying to allocate 1 TB
    if (!arrz) {
        fprintf(stderr, "Error: malloc failed\n");
        return 1;
    }

    
    for (int i=0; i<n; i++){
        if (i<n/2){
            first[i] = arr[i];
        }
        else
        {
            second[i-n/2] = arr[i];
        }
    }
    
    printArray(first, N/2);
    printf("\n");
    printArray(second, N/2);





}