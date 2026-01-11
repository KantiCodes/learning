#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

// void printArray(int *arr, int n) {
//     printf("[");
//     for (int i=0; i<n; i++) {
//         printf("%d,", arr[i]);
//     }
//     printf("]");
//     return;
// }

void mergeImpl(int *left, int *right, int *result, int left_size, int right_size)
{   
    // printf("\t Merging  with sizes: (%d, %d)", left_size, right_size);
    // printArray(left, left_size);
    // printf(" and: ");
    // printArray(right, right_size);
    // printf("\n");


    int i=0, j=0, k=0;
    while (i < left_size && j<right_size)
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
    
    while(i<left_size)
    {
        result[k++] = left[i++];
        // printf("\tFrom first array loop: ");
        // printArray(result, n*2);
        // printf("\n");
    }
    
    while(j<right_size)
    {
        result[k++] = right[j++];
        // printf("\tFrom second array loop: ");
        // printArray(result, n*2);
        // printf("\n");
    }
    // printf("\tMerged into: ");
    // printArray(result, )

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
        // printf("\tI is: %d\n", i);
        int j;
        for (j=0; j<size-i;j= j + i*2)
        {
            int left_size = i;
            int right_size = size > j + i + i ? i : size-j-i;

            mergeImpl(arr+j, arr+j+i, temp+j, left_size, right_size);
            // scanf("%d", &b);
        }
        for (int ii=j;ii<size;ii++)
        {
            temp[ii] = arr[ii];
        }
        // printf("\t\t Temp after full run: ");
        // printArray(temp, size);
        // printf("\n");
        for (int k=0;k<size;k++)
        {
            arr[k] = temp[k];
        }
    }
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {    
    // printf("nums1Size: %d, n: %d, m: %d", nums1Size, n, m);
    // printf("Nums1: ");
    // printArray(nums1,m);
    // printf("\n");
    // printf("Nums2: ");
    // printArray(nums2,n);
    // printf("\n");
    for (int i=0; i<n;i++)
    {
        nums1[m+i] = nums2[i];
    }
    // // printf("Nums1 after merging: ");
    // printArray(nums1,n+m);
    // printf("\n");

    // printArray(nums1, n+m);
    mergeSortInplace(nums1,n+m);
}