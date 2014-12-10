//
//  draw.c
//  laba3
//
//  Created by Sergei Waribrus on 08/12/14.
//  Copyright (c) 2014 Sergei Waribrus. All rights reserved.
//

#include "draw.h"

static void print_text(float x, float y, char *string)
{
    glColor3f(0.0f, 0.0f, 0.0f);
    glRasterPos2f(x, y);
    int len, i;
    len = (int)strlen(string);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
    }
}


namespace_draw const draw = {print_text};