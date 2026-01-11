#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>



#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

void mergeImpl(int *left, int *right, int *result, int left_size, int right_size)
{   

    int i=0, j=0, k=0;
    while (i < left_size && j<right_size)
    {   

        if (left[i] < right[j])
        {   
            result[k++] = left[i++];
        }
        else
        {
            result[k++] = right[j++];
        }

    }
    while(i<left_size)
    {
        result[k++] = left[i++];

    }
    
    while(j<right_size)
    {
        result[k++] = right[j++];

    }
}

void mergeSortInplace(int *arr, int size)
{   
    int temp[size];
    for (int i=1;i<size;i*=2)
    {
        int j;
        for (j=0; j<size-i;j= j + i*2)
        {
            int left_size = i;
            int right_size = MIN(i, size - (j+i));

            mergeImpl(arr+j , arr+j+i, temp+j, left_size, right_size);
        }
        for (int ii=j;ii<size;ii++)
        {
            temp[ii] = arr[ii];
        }

        for (int k=0;k<size;k++)
        {
            arr[k] = temp[k];
        }
    }
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {    

    for (int i=0; i<n;i++)
    {
        nums1[m+i] = nums2[i];
    }
    mergeSortInplace(nums1,n+m);
}