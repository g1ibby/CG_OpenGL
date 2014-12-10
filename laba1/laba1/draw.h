//
//  draw.h
//  laba1
//
//  Created by Sergei Waribrus on 08/12/14.
//  Copyright (c) 2014 Sergei Waribrus. All rights reserved.
//

#ifndef __laba1__draw__
#define __laba1__draw__

#include <stdio.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include "string.h"

typedef struct {
    void (* const printText)(float x, float y, char *string);
} namespace_draw;

extern namespace_draw const draw;

#endif /* defined(__laba1__draw__) */
