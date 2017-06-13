//
//  main.cpp
//  Quicksort
//
//  Created by Oneself on 2017/6/13.
//  Copyright © 2017年 Oneself. All rights reserved.
//

#include <stdio.h>

void quicksort(int *, int, int);

int main(int argc, const char * argv[]) {
    const int arrayLength = 5;
    int array[arrayLength] = {5, 3, 3, 4, 4};
    
    quicksort(array, 0, 4);
    
    for (int index = 0; index < arrayLength; ++index) {
        printf("%d\n", array[index]);
    }
    
    return 0;
}

int findPos(int *array, int low, int high) {
    int val = array[low];
    while (low < high) {
        while (low < high && array[high] >= val) {
            --high;
        }
        array[low] = array[high];
        while (low < high && array[low] <= val) {
            ++low;
        }
        array[high] = array[low];
    }
    array[low] = val;
    
    return low;
}

void quicksort(int *array, int low, int high) {
    if (low < high) {
        int pos = findPos(array, low, high);
        quicksort(array, low, pos - 1);
        quicksort(array, pos + 1, high);
    }
}
