#include "../commons.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#define N 8

void merge(int *left, int *right, int *result, int n)
{   
    printf("\t\t\t Merging arrays with n: %d : ", n);
    printArray(left, n);
    printf(" and: ");
    printArray(right, n);
    printf("\n");


    int i=0, j=0, k=0;
    while (i < n && j<n)
    {   
        // printf("###############################\n");
        // printf("I is: %d, J is: %d, K is: %d\n", i,j,k);
        // printf("Left: %d, Right: %d\n", left[i],right[j]);
        if (left[i] < right[j])
        {   
            // printf("\t left bigger than right: i: %d, j: %d, k: %d\n", i,j,k);
            result[k++] = left[i++];
        }
        else
        {
            result[k++] = right[j++];
        }
        // printf("\tFrom common loop %d: ", k);
        // printArray(result, n*2);
        // printf("\n");
    }
    
    while(i<n)
    {
        result[k++] = left[i++];
        // printf("\tFrom first array loop: ");
        // printArray(result, n*2);
        // printf("\n");
    }
    
    while(j<n)
    {
        result[k++] = right[j++];
        // printf("\tFrom second array loop: ");
        // printArray(result, n*2);
        // printf("\n");
    }

}

void mergeSortInplace(int *arr, int size)
{   
    int b;
    int temp[size];

    // printf("Copied result is: ");
    // printArray(result, size);
    // printf("\n");

    for (int i=1;i<size;i*=2)
    {
        printf("\tI is: %d\n", i);
        for (int j=0; j<size-i;j= j + i*2)
        {
            printf("\t\t I is: %d, J is: %d\n", i, j);
            merge(arr+j, arr+j+i, temp+j, i);
            scanf("%d", &b);
        }
        for (int k=0;k<size;k++)
        {
            arr[k] = temp[k];
        }
    }
}

/*
0 1 2 3 4 5 6 7

a b c d e f g h
6 2 1 4 5 0 7 3
a a b b c c d d
2 6 1 4 0 5 3 7
a a a a b b b b
1 2 4 6 0 3 5 7

0 1 2 3 4 5 6 7
*/

int main(){
    int arr[8] = {6, 2, 1, 4, 5, 0, 7, 3, 9};
    printf("Before running: ");
    printArray(arr+0, 1);
    printf(" and: ");
    printArray(arr+1, 1);
    printf("\n");

    mergeSortInplace(arr, 8);

    printf("Finished !\n");
    printArray(arr, 8);
//     int arr1[N] = {1,3,5,7,9, 11, 13, 15};
//     int arr2[N] = {2,4,6,8,10,12,14,16};
// //     printf("Arr[0]: %d, Arr[1]: %d, Arr[5]: %d", arr1[0], arr1[1], arr1[7]);
// //     // return 0;
// //     int newSize = nearestPower2(N);
// //     int *newArr1 = extendToSize(arr1, N, newSize);
// //     int *newArr2 = extendToSize(arr2, N, newSize);
// //     int bbb[newSize];

// //     printf("Printing array1: ");
// //     printArray(newArr1, newSize);
// //     printf("\n");
// //     printf("Printing array2: ");
// //     printArray(newArr2, newSize);
// //     printf("\n");
    
// //     int *result = malloc(2 * newSize * sizeof(int));
// //     setAllToValue(result, 99999, newSize * 2);
// //     printf("Printing result: ");
// //     printArray(result, newSize * 2);
// //     printf("\n");
// //     merge(arr1, arr2, result, newSize);
// //     printf("\n");
// //     printf("Printing result after merge: ");
// //     printArray(result, newSize * 2);
// //     printf("\n");
// // }

}
