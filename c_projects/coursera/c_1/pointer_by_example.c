#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    const int SIZE = 5;
    int arr[5] = {-9,-8,-7,-6,-5};
    int (*arr_ptr)[5] = &arr;
    int *arr_ptr_first_element = &arr[0];
    
    uintptr_t arr_ptr_uint = (uintptr_t) &arr;
    uintptr_t arr_ptr_uint_plus_4 = arr_ptr_uint + 4;
    uintptr_t arr_ptr_uint_plus_1 = arr_ptr_uint + 1;

    if (arr_ptr != arr_ptr_first_element) {
        printf("1 broken");
        return -1;
    }
    
    if ((int *)arr_ptr + 1 != arr_ptr_first_element+1) {        
        printf("2 broken");
        return -1;
    }
    
    if ((uintptr_t)arr_ptr + 4 != (uintptr_t)(arr_ptr_first_element+1)) {
        printf("3 broken");
        return -1;
    }
    
    
    if (arr_ptr_uint != (uintptr_t)arr_ptr) {
        printf("4 broken");
        return -1;
    }
    
    if (arr_ptr_uint_plus_4 != (uintptr_t)(arr_ptr_first_element+1)) {
        printf("5 broken");
        return -1;
    }

    return 0;
}