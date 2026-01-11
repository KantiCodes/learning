


#include "commons.h"

int main(){
    /*
    Because of operator precedence ++ will be executed after the assignement
    so:
        a[i++] += 100;
    is the same as
        a[i] += 100;
        i++;
    */
    int a[5] = {1,2,3,4,5};
    int i = 0;
    a[i++] += 100;
    printArray(a, 5);
    printf("\n i: %d\n", i);

    
    int b[5] = {11,22,33,44,55};
    int j = 0;
    b[j++] += j;
    printArray(b, 5);
    printf("\n");
    printf("j is: %d\n", j);

    int k = 0;
    int c[5] = {1,2,3,4,5};
    c[k++] = k;
    printArray(c, 5);
    printf("\n");
    printf("k is: %d\n", k);

}