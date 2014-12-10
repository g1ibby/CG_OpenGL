//
//  algorithms.c
//  laba3
//
//  Created by Sergei Waribrus on 08/12/14.
//  Copyright (c) 2014 Sergei Waribrus. All rights reserved.
//

#include "algorithms.h"

static void bubble_sort(int *array, int array_size)
{
    int i, j, temp;
    for (i = 0; i < (array_size - 1); ++i)
    {
        for (j = 0; j < array_size - 1 - i; ++j)
        {
            if (array[j] > array[j+1])
            {
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}

static void quick_sort(int *arr, int elements) {
    #define  MAX_LEVELS  1000
    
    int piv, beg[MAX_LEVELS], end[MAX_LEVELS], i=0, L, R;
    
    beg[0] = 0; end[0] = elements;
    while (i >= 0) {
        L = beg[i]; R = end[i]-1;
        if (L<R) {
            piv=arr[L]; if (i==MAX_LEVELS-1) return;
            while (L<R) {
                while (arr[R]>=piv && L<R) R--; if (L<R) arr[L++]=arr[R];
                while (arr[L]<=piv && L<R) L++; if (L<R) arr[R--]=arr[L]; }
            arr[L]=piv; beg[i+1]=L+1; end[i+1]=end[i]; end[i++]=L; }
        else {
            i--; }}
    return;
}

static void permutation_sort(int *arr, int elements) {
    int flag = 0;
    int i = 0;
    do
    {
        flag = 0;
        i = 0;
        while (i < elements - 1)
        {
            if (arr[i] > arr[i+1])
            {
                int buf = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = buf;
                flag = 1;
            }
            i++;
        }
    }
    while(flag);
}

static int direct_search(int search, int *arr, int elements) {
    for (int i = 0; i < elements; i++) {
        if (arr[i] == search) {
            return i;
        }
    }
    return KEY_NOT_FOUND;
}

static int binary_search(int search, int *arr, int elements) {
    quick_sort(arr, elements);
    
    int imax = elements - 1;
    int imin = 0;
    while (imax >= imin)
    {
        int imid = imin + ((imax - imin) / 2);
        if (arr[imid] == search)
            return imid;
        else if (arr[imid] < search)
            imin = imid + 1;
        else
            imax = imid - 1;
    }
    return KEY_NOT_FOUND;
}

namespace_algorithms const algorithms = {bubble_sort, quick_sort, permutation_sort, direct_search,
    binary_search};
