//
//  algorithms.h
//  laba1
//
//  Created by Sergei Waribrus on 08/12/14.
//  Copyright (c) 2014 Sergei Waribrus. All rights reserved.
//

#ifndef __laba1__algorithms__
#define __laba1__algorithms__

#include <stdio.h>

#define KEY_NOT_FOUND -1;

typedef struct {
    void (* const BubbleSort)(int *array, int array_size);
    void (* const QuickSort)(int *arr, int elements);
    void (* const PermutationSort)(int *arr, int elements);
    int (* const DirectSearch)(int search, int *arr, int elements);
    int (* const BinarySearch)(int search, int *arr, int elements);
} namespace_algorithms;

extern namespace_algorithms const algorithms;


#endif /* defined(__laba1__algorithms__) */
