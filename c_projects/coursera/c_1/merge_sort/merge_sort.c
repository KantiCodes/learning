#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "commons.h"
#define N 6


int *conquer(int *arr1, int n1, int *arr2, int n2) {
    int nm = n1 +n2;
    int i=0, j=0;
    int *result = malloc(sizeof(int) * nm);
    if (result == NULL) {
        printf("Unable to allocate memory");
        return NULL;  // Exit the program with an error code
        }

    int tmp;
    while (i < n1 | j < n2) {
        if (i == n1) {
            tmp = arr2[j];
            j++;
        }
        else if (j == n2)
        {
            tmp = arr1[i];
            i++;
        }
        else 
        {
            if (arr1[i] >= arr2[j])
            {
                tmp = arr2[j];
                j++;
            }
            else
            {
                tmp = arr1[i];
                i++;
            }
        }
        // -1 since we already incremented one of i or j
        printf("\ni:%d, j:%d, i+j-1: %d\n",i,j,i+j-1);
        result[i+j-1] = tmp;
        

    }
    printf("Merging; The two arrays:\t");
    printArray(arr1, n1);
    printf(" and: \t");
    printArray(arr2, n2);
    free(arr1);
    free(arr2);
    printf("\t Were merged into:\t");
    printArray(result, nm);
    printf("\n");
    return result;
}


int* mergeSort(int *arr, int n) {
    
    if (n == 1) {
        return arr;
    }
    else {
        printf("\n####################################\n");
        printf("Array:\t");
        printArray(arr, n);
        printf("\n");
        int half = n/2;
        int extra = n%2;
        int len_1 = half;
        int len_2 = half + extra;
        int *arr1 = malloc(sizeof(int) * len_1);
        int *arr2 = malloc(sizeof(int) * len_2);
        for (int i=0; i<n;i++){
            if (i < n/2) {
                arr1[i] = arr[i]; 
            }
            else
            {
                arr2[i-n/2] = arr[i];
            }
        }
        printf("Dividing; Was split into:\t");
        printArray(arr1, len_1);
        printf(" and: \t");
        printArray(arr2, len_2);
        printf("\n");
        int *sorted_arr1 = mergeSort(arr1, len_1);
        int *sorted_arr2 = mergeSort(arr2, len_2);
        return conquer(sorted_arr1, len_1, sorted_arr2, len_2);
    }
}


int main() {
    int a[N] = {-111,2,5,1,1,1};
    int *b = a;
    // printf("size of a: %lu\n", sizeof(a));
    // printf("size of b: %lu\n", sizeof(&b));
    // printf("size of: %lu\n", sizeof(a) / sizeof (a[0]));
    // // printf("Size of: %d\n", len(a));
    printArray(a, N);
    printf("\n");
    int *sorted = mergeSort(a, N);

    printArray(sorted, N);


}