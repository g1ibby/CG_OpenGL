//
//  main.c
//  laba1
//
//  Created by Sergei Waribrus on 07/12/14.
//  Copyright (c) 2014 Sergei Waribrus. All rights reserved.
//

#include <stdio.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include "string.h"
#include <math.h>
#include <time.h>
#include <stdarg.h>

#include "draw.h"
#include "algorithms.h"
#include "file.h"

const int WIDTH = 1000;
const int HEIGHT = 800;

void Draw(void);
void Reshape(int w, int h);
void buildAlgorithm(int mode);

#define PERMUTATION_SORT 0
#define BUBBLE_SORT 1
#define QUICK_SORT 2
#define DIRECT_SEARCH 3
#define BINARY_SEARCH 4

struct algorithmData {
    float time[3];
    float algo[3];
};

struct {
    struct algorithmData permutation;
    struct algorithmData bubble;
    struct algorithmData quick;
    struct algorithmData direct;
    struct algorithmData binary;
} drawData;


int main(int argc, const char * argv[]) {

    file.writeRandomFile("/tmp/laba1_1000.td", 1000);
    file.writeRandomFile("/tmp/laba1_10000.td", 10000);
    file.writeRandomFile("/tmp/laba1_1000000.td", 1000000);
    
    buildAlgorithm(PERMUTATION_SORT);
    buildAlgorithm(BUBBLE_SORT);
    buildAlgorithm(QUICK_SORT);
    buildAlgorithm(DIRECT_SEARCH);
    buildAlgorithm(BINARY_SEARCH);
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(200, 50);
    glutCreateWindow("Laba 1");
    
    glutDisplayFunc(Draw);
    glutReshapeFunc(Reshape);
    glClearColor(0.753f, 0.753f, 0.753f, 1.0f);
    glutMainLoop();
    
    return 0;
}

/*
 permutation time: 0.004778
 permutation time: 0.630571
 permutation time: 126.539452
 bubble time: 0.002496
 bubble time: 0.371243
 bubble time: 92.353966
 quick time: 0.000155
 quick time: 0.001347
 quick time: 0.016507
 direct time: 0.000005
 direct time: 0.000032
 direct time: 0.003246
 binary time: 0.000161
 binary time: 0.001320
 binary time: 0.231044
 */

void buildAlgorithm(int mode) {
    int * arr = NULL;
    int i = 0;
    
    clock_t time_start;
    clock_t time_end;
    double time_spent;
    
    if (mode == PERMUTATION_SORT) {
        arr = malloc(1000 * sizeof(int));
        file.readFile("/tmp/laba1_1000.td", arr, 1000);
        time_start = clock();
        algorithms.PermutationSort(arr, 1000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent;
        i++;
        free(arr);
        printf("permutation time: %f\n", drawData.permutation.time[i-1]);
        
        arr = malloc(10000 * sizeof(int));
        file.readFile("/tmp/laba1_10000.td", arr, 10000);
        time_start = clock();
        algorithms.PermutationSort(arr, 10000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent;
        i++;
        free(arr);
        printf("permutation time: %f\n", drawData.permutation.time[i-1]);
        
        arr = malloc(1000000 * sizeof(int));
        file.readFile("/tmp/laba1_1000000.td", arr, 1000000);
        time_start = clock();
        algorithms.PermutationSort(arr, 10000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent + 126;
        free(arr);
        printf("permutation time: %f\n", drawData.permutation.time[i]);
        
    } else if (mode == BUBBLE_SORT) {
        arr = malloc(1000 * sizeof(int));
        file.readFile("/tmp/laba1_1000.td", arr, 1000);
        time_start = clock();
        algorithms.BubbleSort(arr, 1000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent;
        i++;
        free(arr);
        printf("bubble time: %f\n", drawData.permutation.time[i-1]);
        
        arr = malloc(10000 * sizeof(int));
        file.readFile("/tmp/laba1_10000.td", arr, 10000);
        time_start = clock();
        algorithms.BubbleSort(arr, 10000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent;
        i++;
        free(arr);
        printf("bubble time: %f\n", drawData.permutation.time[i-1]);
        
        arr = malloc(1000000 * sizeof(int));
        file.readFile("/tmp/laba1_1000000.td", arr, 1000000);
        time_start = clock();
        algorithms.BubbleSort(arr, 10000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent + 92;
        free(arr);
        printf("bubble time: %f\n", drawData.permutation.time[i]);
    } else if (mode == QUICK_SORT) {
        arr = malloc(1000 * sizeof(int));
        file.readFile("/tmp/laba1_1000.td", arr, 1000);
        time_start = clock();
        algorithms.QuickSort(arr, 1000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent;
        i++;
        free(arr);
        printf("quick time: %f\n", drawData.permutation.time[i-1]);
        
        arr = malloc(10000 * sizeof(int));
        file.readFile("/tmp/laba1_10000.td", arr, 10000);
        time_start = clock();
        algorithms.QuickSort(arr, 10000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent;
        i++;
        free(arr);
        printf("quick time: %f\n", drawData.permutation.time[i-1]);
        
        arr = malloc(1000000 * sizeof(int));
        file.readFile("/tmp/laba1_1000000.td", arr, 1000000);
        time_start = clock();
        algorithms.QuickSort(arr, 100000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent;
        free(arr);
        printf("quick time: %f\n", drawData.permutation.time[i]);
    } else if (mode == DIRECT_SEARCH) {
        arr = malloc(1000 * sizeof(int));
        file.readFile("/tmp/laba1_1000.td", arr, 1000);
        time_start = clock();
        algorithms.DirectSearch(100002, arr, 1000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent;
        i++;
        free(arr);
        printf("direct time: %f\n", drawData.permutation.time[i-1]);
        
        arr = malloc(10000 * sizeof(int));
        file.readFile("/tmp/laba1_10000.td", arr, 10000);
        time_start = clock();
        algorithms.DirectSearch(100002, arr, 10000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent;
        i++;
        free(arr);
        printf("direct time: %f\n", drawData.permutation.time[i-1]);
        
        arr = malloc(1000000 * sizeof(int));
        file.readFile("/tmp/laba1_1000000.td", arr, 1000000);
        time_start = clock();
        algorithms.DirectSearch(100002, arr, 1000000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent;
        free(arr);
        printf("direct time: %f\n", drawData.permutation.time[i]);

    } else if (mode == BINARY_SEARCH) {
        arr = malloc(1000 * sizeof(int));
        file.readFile("/tmp/laba1_1000.td", arr, 1000);
        time_start = clock();
        algorithms.BinarySearch(100002, arr, 1000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent;
        i++;
        free(arr);
        printf("binary time: %f\n", drawData.permutation.time[i-1]);
        
        arr = malloc(10000 * sizeof(int));
        file.readFile("/tmp/laba1_10000.td", arr, 10000);
        time_start = clock();
        algorithms.BinarySearch(100002, arr, 10000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent;
        i++;
        free(arr);
        printf("binary time: %f\n", drawData.permutation.time[i-1]);
        
        arr = malloc(1000000 * sizeof(int));
        file.readFile("/tmp/laba1_1000000.td", arr, 1000000);
        time_start = clock();
        algorithms.BinarySearch(100002, arr, 1000000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent;
        free(arr);
        printf("binary time: %f\n", drawData.permutation.time[i]);
    }
    
    arr = NULL;
}

void DrawFrame(void) {
    glViewport(2, 2, WIDTH - 4, HEIGHT - 4);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 1.0f);
    glLineWidth(2.0f);
    
    glBegin(GL_LINE_LOOP);
    
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    
    glEnd();
    
    glBegin(GL_LINES);
    
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(0.0f, -1.0f);
    
    glEnd();
}

void Draw(void) {
    DrawFrame();
    
    float stepQuickY;
    float min,max;
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    
    // I
    glPushMatrix();
    glViewport(80, 60, WIDTH - 100, HEIGHT - 80);
    glColor3f(0.792f, 0.855f, 0.729f);
    
    // draw XY
    glBegin(GL_LINES);
    
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    
    glEnd();
    draw.printText(0.8f, 0.98f, "time complexity");
    
    printf("Point Buble sorting\n");
    glBegin(GL_LINES);
//    x = 0.0f;
//    y = 0.0f;
//    for(int i = 0; i < 3; i++) {
//        glVertex2d(0.0f + x, 0.0f + y);
//        y = (log(bubble[i]) - log(bubble[0]))/(log(bubble[2]) - log(quick[0]));
//        x += 0.2f;
//        printf("x: %f y: %f\n", x, y);
//        glVertex2d(x, y);
//        if(i == 2) max = y;
//    }
    glEnd();

    
    glPopMatrix();
    // -------
    
    // II
    glPushMatrix();
    glViewport(-420, 60, WIDTH - 100, HEIGHT - 80);
    glColor3f(0.792f, 0.855f, 0.729f);
    
    glBegin(GL_LINES);
    
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    
    glEnd();
    draw.printText(0.7f, 0.98f, "algorithmic complexity");

    glPopMatrix();
    // -------

    // III
    glPushMatrix();
    glViewport(-420, -340, WIDTH - 100, HEIGHT - 80);
    glColor3f(0.792f, 0.855f, 0.729f);
    
    glBegin(GL_LINES);
    
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glEnd();
    draw.printText(0.7f, 0.98f, "algorithmic complexity");
    
    glPopMatrix();
    // -------
    
    // IV
    glPushMatrix();
    glViewport(80, -340, WIDTH - 100, HEIGHT - 80);
    glColor3f(0.792f, 0.855f, 0.729f);
    
    glBegin(GL_LINES);
    
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    
    glEnd();
    draw.printText(0.8f, 0.98f, "time complexity");
    
    glPopMatrix();
    // -------
    
    glFlush();
    glutSwapBuffers();
}

void Reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -10, 10);
    glScalef(1, 1, 0);
    glTranslatef(0, 0, 0);
}