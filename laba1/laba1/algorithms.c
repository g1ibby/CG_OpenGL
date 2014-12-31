//
//  algorithms.c
//  laba3
//
//  Created by Sergei Waribrus on 08/12/14.
//  Copyright (c) 2014 Sergei Waribrus. All rights reserved.
//

#include "algorithms.h"

static uint64_t bubble_sort(short int *array, int array_size)
{
    uint64_t algo = 0;
    int i, j, temp;
    for (i = 0; i < array_size - 1; i++)
    {
        for (j = 0; j < array_size - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                algo++;
            }
        }
    }
    return algo;
}

static uint64_t quick_sort(short int *arr, int elements) {
    #define  MAX_LEVELS  1000
    
    uint64_t algo = 0;
    
    int piv, beg[MAX_LEVELS], end[MAX_LEVELS], i=0, L, R;
    
    beg[0] = 0; end[0] = elements;
    while (i >= 0) {
        L = beg[i]; R = end[i]-1;
        if (L<R) {
            piv=arr[L]; if (i==MAX_LEVELS-1) return algo;
            while (L<R) {
                while (arr[R]>=piv && L<R) R--; if (L<R) arr[L++]=arr[R];
                while (arr[L]<=piv && L<R) L++; if (L<R) arr[R--]=arr[L]; }
            arr[L]=piv; beg[i+1]=L+1; end[i+1]=end[i]; end[i++]=L; }
        else {
            i--; }}
    return algo;
}

static uint64_t permutation_sort(short int *arr, int elements) {
    uint64_t algo = 0;
    
    int i = 0, tmp;
    while (i < elements - 1)
    {
        if (arr[i+1] < arr[i])
        {
            tmp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = tmp;
            i = 0;
        }
        else i++;
    }
    
    return algo;
}

static uint64_t direct_search(short int search, short int *arr, int elements) {
    uint64_t algo = 0;
    for (int i = 0; i < elements; i++) {
        algo++;
        if (arr[i] == search) {
            return algo;
        }
    }
    return algo;
}

static uint64_t binary_search(short int search, short int *arr, int elements) {
    uint64_t algo = 0;
    algo = algo + quick_sort(arr, elements);
    
    int imax = elements - 1;
    int imin = 0;
    while (imax >= imin)
    {
        algo++;
        int imid = imin + ((imax - imin) / 2);
        if (arr[imid] == search)
            return algo;
        else if (arr[imid] < search)
            imin = imid + 1;
        else
            imax = imid - 1;
    }
    return algo;
}

namespace_algorithms const algorithms = {bubble_sort, quick_sort, permutation_sort, direct_search,
    binary_search};
