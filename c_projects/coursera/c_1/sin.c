#include<stdio.h>
#include<math.h> 
#include<stdlib.h>


/*
Iterates over the range <0,1> n in steps and prints the result of calling function for each value.
*/
void printFunc(int n, double (*f)(double)) {
    double step = 1./n;
    printf("The steps is: %lf\n", step);
    for(double i=0; i<=1; i+=step){
        printf("%lf ", f(i));
    }
} 


int main(void) { 
    int steps;
    printf("Give me a number!\n");
    scanf("%d", &steps);
    printf("Running for function: %s\n", "sin");
    printFunc(steps, sin);
    printf("\n");
    printf("Running for function: %s\n", "cos");
    printFunc(steps, cos);
}
