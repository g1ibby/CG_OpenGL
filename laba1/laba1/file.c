//
//  file.c
//  laba3
//
//  Created by Sergei Waribrus on 08/12/14.
//  Copyright (c) 2014 Sergei Waribrus. All rights reserved.
//

#include "file.h"

int getRand(void)
{
    return 1 + (int) (100000.0 * (rand() / (RAND_MAX + 1.0)));
}

static void write_random_file(const char * name, int count) {
    FILE *fd = fopen(name, "w+");
    if(fd) {
        for(int i = 0; i < count; i++) {
            fprintf(fd, "%d\n", getRand());
        }
        fclose(fd);
    }
}

static void read_file(const char * name, int *array, int count) {
    FILE *fp = fopen(name, "r");
    if(fp) {
        int buf = 0;
        for (int i = 0; i < count; i++) {
            fscanf(fp, "%d", &buf);
            array[i] = buf;
        }
        fclose(fp);
    }
}

namespace_file const file = {write_random_file, read_file};