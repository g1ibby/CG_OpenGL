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
    uint64_t (* const BubbleSort)(short int *array, int array_size);
    uint64_t (* const QuickSort)(short int *arr, int elements);
    uint64_t (* const PermutationSort)(short int *arr, int elements);
    uint64_t (* const DirectSearch)(short int search, short int *arr, int elements);
    uint64_t (* const BinarySearch)(short int search, short int *arr, int elements);
} namespace_algorithms;

extern namespace_algorithms const algorithms;


#endif /* defined(__laba1__algorithms__) */
