/*
    File to display differences in how pointers can be treated and their arithmetics
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    const int SIZE = 5;
    int arr[5] = {-9,-8,-7,-6,-5};
    int (*arr_ptr)[5] = &arr;
    int *arr_ptr_zeroth_element = &arr[0];
    
    uintptr_t arr_ptr_uint = (uintptr_t) &arr;
    uintptr_t arr_ptr_uint_plus_4 = arr_ptr_uint + 4;
    uintptr_t arr_ptr_uint_plus_1 = arr_ptr_uint + 1;

    /*
        Although the arr_ptr is a pointer to the array
        and the arr_ptr_first_element is a pointer to the first element
        they have the same address BUT ARE OF A DIFFERENT TYPE!!!
    */
    if (arr_ptr != arr_ptr_zeroth_element) {
        printf("1 broken");
        return -1;
    }
    
    /*
        Here the important bit is to type converrt the arr_ptr to (int *)
        prior to adding +1, as if that wasn't done then the pointer arithmetics
        would add the size of array (5*4bytes) instead of the size of a single element (4 bytes for int)
    */
    if ((int *)arr_ptr + 1 != arr_ptr_zeroth_element+1) {
        printf("2 broken");
        return -1;
    }

    /*
        If we convert the arr_ptr to a uintptr_t type, which stands for unsigned long
        then it's treated as a numeric value, therefore we need to add 4 bytes to match
        the `arr_ptr_first_element+1`.

        The +1 in `arr_ptr_first_element+1` will be treated as 4 bytes as
        arr_ptr_first_element is a of type int * and the pointer arithmetic will correctly
        add number of bytes in the element stored in the array (int)
    */
    if ((uintptr_t)arr_ptr + 4 != (uintptr_t)(arr_ptr_zeroth_element+1)) {
        printf("3 broken");
        return -1;
    }
    
    
    if (arr_ptr_uint != (uintptr_t)arr_ptr) {
        printf("4 broken");
        return -1;
    }

    if (arr_ptr_uint != (uintptr_t)arr_ptr_zeroth_element) {
        printf("5 broken");
        return -1;
    }

    /*
        Pointer arithmetic of 0th element + 1 will point to address of the 1st element
        Then it's derefereced
    */
    if (*(arr_ptr_zeroth_element+1) != arr[1]) {
        printf("6 broken, pointer evaluated to %d", *(arr_ptr_zeroth_element+1));
        return -1;
    }

    if (*(int *)((uintptr_t)arr_ptr + 4) != arr[1]) {
        printf("7 broken: %d", *(int *)((uintptr_t)arr_ptr + 4));
        return -1;
    }

    return 0;
}