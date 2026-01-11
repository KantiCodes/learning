
#ifndef COMMONS_H
#define COMMONS_H

#include <stdio.h>

void printArray(int *arr, int n);


int nearestPower2(int n);

int *extendToSize(int *arr, int originalSize, int desiredSize);

void swap(int *a, int *b);

void setAllToValue(int *arr, int value, int n);

#endif