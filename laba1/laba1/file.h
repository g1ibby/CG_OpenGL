//
//  file.h
//  laba1
//
//  Created by Sergei Waribrus on 08/12/14.
//  Copyright (c) 2014 Sergei Waribrus. All rights reserved.
//

#ifndef __laba1__file__
#define __laba1__file__

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void (* const writeRandomFile)(const char * name, int count);
    void (* const readFile)(const char * name, int *array, int count);
} namespace_file;

extern namespace_file const file;

#endif /* defined(__laba1__file__) */
