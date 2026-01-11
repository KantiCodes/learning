#include <stdio.h>
#include "commons.h"
#include <stdlib.h>
#include <memory.h>
#include <math.h>

void printArray(int *arr, int n) {
    printf("[");
    for (int i=0; i<n; i++) {
        printf("%d,", arr[i]);
    }
    printf("]");
    return;
}

void swap(int *a, int *b){
    *a = *b ^ *a; // b xor a
    *b = *a ^ *b; // b xor a xor b = a
    *a = *a ^*b; // b xor a xor a = b4

}


bool isArray

int *extendToSize(int *arr, int originalSize, int desiredSize)
{
    int *newArray = calloc(desiredSize, sizeof(int));
    memcpy(newArray, arr, sizeof(int) * originalSize);
    return newArray;
    
}

void setAllToValue(int *arr, int value, int n)
{
    for (int i=0; i<n; i++) {
        arr[i] = value;
    }
}

int nearestPower2(int n)
{

    int power = 0;
    while (n > pow(2, power))
    {
        power ++;
    }
    int result = pow(2, power);
    printf("\n Nerest pow 2 of n: %d, is: %d\n", n, result);
    return result;
}
