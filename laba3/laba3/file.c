//
//  file.c
//  laba3
//
//  Created by Sergei Waribrus on 08/12/14.
//  Copyright (c) 2014 Sergei Waribrus. All rights reserved.
//

#include "file.h"

float getRand(void)
{
    return ((float) rand() / (RAND_MAX));
}

static void write_random_file(const char * name, int count) {
    FILE *fd = fopen(name, "a+");
    if(fd) {
        for(int i = 0; i < count; i++) {
            fprintf(fd, "%f %f\n", getRand(), getRand());
        }
        fclose(fd);
    }
}

static void read_file(const char * name, struct lPoint *array, int count) {
    FILE *fp = fopen(name, "r");
    if(fp) {
        float buf_x = 0;
        float buf_y = 0;
        for (int i = 0; i < count; i++) {
            fscanf(fp, "%f %f", &buf_x, &buf_y);
            array[i].x = buf_x;
            array[i].y = buf_y;
        }
        fclose(fp);
    }
}

namespace_file const file = {write_random_file, read_file};