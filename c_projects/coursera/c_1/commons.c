#include <stdio.h>
#include "commons.h"

void printArray(int *arr, int n) {
    for (int i=0; i<n; i++) {
        printf("\t%d", arr[i]);
    }
    return;
}

void swap(int *a, int *b){
    *a = *b ^ *a; // b xor a
    *b = *a ^ *b; // b xor a xor b = a
    *a = *a ^*b; // b xor a xor a = b4

}