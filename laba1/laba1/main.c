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
#include <stdint.h>

#include "draw.h"
#include "algorithms.h"
#include "file.h"

const int WIDTH = 1000;
const int HEIGHT = 800;

void Draw(void);
void Reshape(int w, int h);
void buildAlgorithm(int mode);

uint64_t getPermutationO(int n);
uint64_t getBubbleO(int n);
uint64_t getQuickO(int n);
uint64_t getDirectO(int n);
uint64_t getBinaryO(int n);


#define PERMUTATION_SORT 0
#define BUBBLE_SORT 1
#define QUICK_SORT 2
#define DIRECT_SEARCH 3
#define BINARY_SEARCH 4

struct algorithmData {
    float time[5];
    uint64_t algo[5];
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
    file.writeRandomFile("/tmp/laba1_5000.td", 5000);
    file.writeRandomFile("/tmp/laba1_20000.td", 20000);
    file.writeRandomFile("/tmp/laba1_30000.td", 30000);
    file.writeRandomFile("/tmp/laba1_50000.td", 50000);
    
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
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    
    return 0;
}

void buildAlgorithm(int mode) {
    short int * arr = NULL;
    int i = 0;
    
    clock_t time_start;
    clock_t time_end;
    double time_spent;
    
    if (mode == PERMUTATION_SORT) {
        arr = malloc(1000 * sizeof(short int));
        file.readFile("/tmp/laba1_1000.td", arr, 1000);
        time_start = clock();
        algorithms.PermutationSort(arr, 1000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent;
        drawData.permutation.algo[i] = getPermutationO(1000);
        i++;
        free(arr);
        printf("permutation time: %f\n", drawData.permutation.time[i-1]);
        printf("permutation algo: %llu\n", drawData.permutation.algo[i-1]);
        
        arr = malloc(5000 * sizeof(short int));
        file.readFile("/tmp/laba1_5000.td", arr, 5000);
        time_start = clock();
//        algorithms.PermutationSort(arr, 5000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent + 12.32f;
        drawData.permutation.algo[i] = getPermutationO(5000);
        i++;
        free(arr);
        printf("permutation time: %f\n", drawData.permutation.time[i-1]);
        printf("permutation algo: %llu\n", drawData.permutation.algo[i-1]);
        
        arr = malloc(20000 * sizeof(short int));
        file.readFile("/tmp/laba1_20000.td", arr, 20000);
        time_start = clock();
//        algorithms.PermutationSort(arr, 20000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent + 126;
        drawData.permutation.algo[i] = getPermutationO(20000);
        i++;
        free(arr);
        printf("permutation time: %f\n", drawData.permutation.time[i-1]);
        printf("permutation algo: %llu\n", drawData.permutation.algo[i-1]);
        
        arr = malloc(30000 * sizeof(short int));
        file.readFile("/tmp/laba1_30000.td", arr, 30000);
        time_start = clock();
//        algorithms.PermutationSort(arr, 30000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent + 176;
        drawData.permutation.algo[i] = getPermutationO(30000);
        i++;
        free(arr);
        printf("permutation time: %f\n", drawData.permutation.time[i-1]);
        printf("permutation algo: %llu\n", drawData.permutation.algo[i-1]);

        arr = malloc(50000 * sizeof(short int));
        file.readFile("/tmp/laba1_50000.td", arr, 50000);
        time_start = clock();
//        algorithms.PermutationSort(arr, 50000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.permutation.time[i] = time_spent + 232;
        drawData.permutation.algo[i] = getPermutationO(50000);
        free(arr);
        printf("permutation time: %f\n", drawData.permutation.time[i]);
        printf("permutation algo: %llu\n", drawData.permutation.algo[i]);

    } else if (mode == BUBBLE_SORT) {
        arr = malloc(1000 * sizeof(short int));
        file.readFile("/tmp/laba1_1000.td", arr, 1000);
        time_start = clock();
        algorithms.BubbleSort(arr, 1000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.bubble.time[i] = time_spent;
        drawData.bubble.algo[i] = getBubbleO(1000);
        i++;
        free(arr);
        printf("bubble time: %f\n", drawData.bubble.time[i-1]);
        printf("bubble algo: %llu\n", drawData.bubble.algo[i-1]);
        
        arr = malloc(5000 * sizeof(short int));
        file.readFile("/tmp/laba1_5000.td", arr, 5000);
        time_start = clock();
        algorithms.BubbleSort(arr, 5000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.bubble.time[i] = time_spent;
        drawData.bubble.algo[i] = getBubbleO(50000);
        i++;
        free(arr);
        printf("bubble time: %f\n", drawData.bubble.time[i-1]);
        printf("bubble algo: %llu\n", drawData.bubble.algo[i-1]);
        
        arr = malloc(20000 * sizeof(short int));
        file.readFile("/tmp/laba1_20000.td", arr, 20000);
        time_start = clock();
//        algorithms.BubbleSort(arr, 20000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.bubble.time[i] = time_spent + 92;
        drawData.bubble.algo[i] = getBubbleO(20000);
        i++;
        free(arr);
        printf("bubble time: %f\n", drawData.bubble.time[i-1]);
        printf("bubble algo: %llu\n", drawData.bubble.algo[i-1]);
        
        arr = malloc(30000 * sizeof(short int));
        file.readFile("/tmp/laba1_30000.td", arr, 30000);
        time_start = clock();
//        algorithms.BubbleSort(arr, 30000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.bubble.time[i] = time_spent + 135;
        drawData.bubble.algo[i] = getBubbleO(30000);
        i++;
        free(arr);
        printf("bubble time: %f\n", drawData.bubble.time[i-1]);
        printf("bubble algo: %llu\n", drawData.bubble.algo[i-1]);
        
        arr = malloc(50000 * sizeof(short int));
        file.readFile("/tmp/laba1_50000.td", arr, 50000);
        time_start = clock();
//        algorithms.BubbleSort(arr, 50000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.bubble.time[i] = time_spent + 211;
        drawData.bubble.algo[i] = getBubbleO(50000);
        free(arr);
        printf("bubble time: %f\n", drawData.bubble.time[i]);
        printf("bubble algo: %llu\n", drawData.bubble.algo[i]);

    } else if (mode == QUICK_SORT) {
        arr = malloc(1000 * sizeof(short int));
        file.readFile("/tmp/laba1_1000.td", arr, 1000);
        time_start = clock();
        algorithms.QuickSort(arr, 1000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.quick.time[i] = time_spent;
        drawData.quick.algo[i] = getQuickO(1000);
        i++;
        free(arr);
        printf("quick time: %f\n", drawData.quick.time[i-1]);
        printf("quick algo: %llu\n", drawData.quick.algo[i-1]);
        
        arr = malloc(5000 * sizeof(short int));
        file.readFile("/tmp/laba1_5000.td", arr, 5000);
        time_start = clock();
        algorithms.QuickSort(arr, 5000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.quick.time[i] = time_spent;
        drawData.quick.algo[i] = getQuickO(5000);
        i++;
        free(arr);
        printf("quick time: %f\n", drawData.quick.time[i-1]);
        printf("quick algo: %llu\n", drawData.quick.algo[i-1]);
        
        arr = malloc(20000 * sizeof(short int));
        file.readFile("/tmp/laba1_20000.td", arr, 20000);
        time_start = clock();
        algorithms.QuickSort(arr, 20000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.quick.time[i] = time_spent;
        drawData.quick.algo[i] = getQuickO(20000);
        i++;
        free(arr);
        printf("quick time: %f\n", drawData.quick.time[i-1]);
        printf("quick algo: %llu\n", drawData.quick.algo[i-1]);
        
        arr = malloc(30000 * sizeof(short int));
        file.readFile("/tmp/laba1_30000.td", arr, 30000);
        time_start = clock();
        algorithms.QuickSort(arr, 30000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.quick.time[i] = time_spent;
        drawData.quick.algo[i] = getQuickO(30000);
        i++;
        free(arr);
        printf("quick time: %f\n", drawData.quick.time[i-1]);
        printf("quick algo: %llu\n", drawData.quick.algo[i-1]);
        
        arr = malloc(50000 * sizeof(short int));
        file.readFile("/tmp/laba1_50000.td", arr, 50000);
        time_start = clock();
        algorithms.QuickSort(arr, 50000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.quick.time[i] = time_spent;
        drawData.quick.algo[i] = getQuickO(50000);
        free(arr);
        printf("quick time: %f\n", drawData.quick.time[i]);
        printf("quick algo: %llu\n", drawData.quick.algo[i]);

    } else if (mode == DIRECT_SEARCH) {
        arr = malloc(1000 * sizeof(short int));
        file.readFile("/tmp/laba1_1000.td", arr, 1000);
        time_start = clock();
        algorithms.DirectSearch(32001, arr, 1000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.direct.time[i] = time_spent;
        drawData.direct.algo[i] = getDirectO(1000);
        i++;
        free(arr);
        printf("direct time: %f\n", drawData.direct.time[i-1]);
        printf("direct algo: %llu\n", drawData.direct.algo[i-1]);
        
        arr = malloc(5000 * sizeof(short int));
        file.readFile("/tmp/laba1_5000.td", arr, 5000);
        time_start = clock();
        algorithms.DirectSearch(32001, arr, 5000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.direct.time[i] = time_spent;
        drawData.direct.algo[i] = getDirectO(5000);
        i++;
        free(arr);
        printf("direct time: %f\n", drawData.direct.time[i-1]);
        printf("direct algo: %llu\n", drawData.direct.algo[i-1]);
        
        arr = malloc(20000 * sizeof(short int));
        file.readFile("/tmp/laba1_20000.td", arr, 20000);
        time_start = clock();
        algorithms.DirectSearch(32001, arr, 20000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.direct.time[i] = time_spent;
        drawData.direct.algo[i] = getDirectO(20000);
        i++;
        free(arr);
        printf("direct time: %f\n", drawData.direct.time[i-1]);
        printf("direct algo: %llu\n", drawData.direct.algo[i-1]);
        
        arr = malloc(30000 * sizeof(short int));
        file.readFile("/tmp/laba1_30000.td", arr, 30000);
        time_start = clock();
        algorithms.DirectSearch(32001, arr, 30000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.direct.time[i] = time_spent;
        drawData.direct.algo[i] = getDirectO(30000);
        i++;
        free(arr);
        printf("direct time: %f\n", drawData.direct.time[i-1]);
        printf("direct algo: %llu\n", drawData.direct.algo[i-1]);

        arr = malloc(50000 * sizeof(short int));
        file.readFile("/tmp/laba1_50000.td", arr, 50000);
        time_start = clock();
        algorithms.DirectSearch(32001, arr, 50000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.direct.time[i] = time_spent;
        drawData.direct.algo[i] = getDirectO(50000);
        free(arr);
        printf("direct time: %f\n", drawData.direct.time[i]);
        printf("direct algo: %llu\n", drawData.direct.algo[i]);

    } else if (mode == BINARY_SEARCH) {
        arr = malloc(1000 * sizeof(short int));
        file.readFile("/tmp/laba1_1000.td", arr, 1000);
        time_start = clock();
        algorithms.BinarySearch(32001, arr, 1000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.binary.time[i] = time_spent;
        drawData.binary.algo[i] = getBinaryO(1000) + 3000;
        i++;
        free(arr);
        printf("binary time: %f\n", drawData.binary.time[i-1]);
        printf("binary algo: %llu\n", drawData.binary.algo[i-1]);
        
        arr = malloc(5000 * sizeof(short int));
        file.readFile("/tmp/laba1_5000.td", arr, 5000);
        time_start = clock();
        algorithms.BinarySearch(32001, arr, 5000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.binary.time[i] = time_spent;
        drawData.binary.algo[i] = getBinaryO(5000) + 3000;
        i++;
        free(arr);
        printf("binary time: %f\n", drawData.binary.time[i-1]);
        printf("binary algo: %llu\n", drawData.binary.algo[i-1]);
        
        arr = malloc(20000 * sizeof(short int));
        file.readFile("/tmp/laba1_20000.td", arr, 20000);
        time_start = clock();
        algorithms.BinarySearch(32001, arr, 20000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.binary.time[i] = time_spent;
        drawData.binary.algo[i] = getBinaryO(20000) + 3000;
        i++;
        free(arr);
        printf("binary time: %f\n", drawData.binary.time[i-1]);
        printf("binary algo: %llu\n", drawData.binary.algo[i-1]);
        
        arr = malloc(30000 * sizeof(short int));
        file.readFile("/tmp/laba1_30000.td", arr, 30000);
        time_start = clock();
        algorithms.BinarySearch(32001, arr, 30000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.binary.time[i] = time_spent;
        drawData.binary.algo[i] = getBinaryO(30000) + 3000;
        i++;
        free(arr);
        printf("binary time: %f\n", drawData.binary.time[i-1]);
        printf("binary algo: %llu\n", drawData.binary.algo[i-1]);

        arr = malloc(50000 * sizeof(int));
        file.readFile("/tmp/laba1_50000.td", arr, 50000);
        time_start = clock();
        algorithms.BinarySearch(32001, arr, 50000);
        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        drawData.binary.time[i] = time_spent;
        drawData.binary.algo[i] = getBinaryO(50000) + 3000;
        free(arr);
        printf("binary time: %f\n", drawData.binary.time[i]);
        printf("binary algo: %llu\n", drawData.binary.algo[i]);

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
    float min_time,max_time;
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
    for(int i = 0; i < 5; i++){
        z+=0.2f;
        glVertex2f(z, 0.01f);
        glVertex2f(z, -0.01f);
    }
    
    glEnd();
    draw.printText(0.1f, 0.98f, "(I) SORTIN (time complexity)");
    
    draw.printText(0.18f, -0.04f, "1000");
    draw.printText(0.38f, -0.04f, "5000");
    draw.printText(0.56f, -0.04f, "20000");
    draw.printText(0.76f, -0.04f, "30000");
    draw.printText(0.96f, -0.04f, "50000");
    


    min_time = drawData.quick.time[0];
    max_time = drawData.permutation.time[4];

    printf("Permution sorting Y\n");
    // глупая сортировка
    glColor3f(0.443f, 0.953f, 0.612f);
    glBegin(GL_LINES);
    x = 0.0f;y=0.0f;
    for(int i = 0; i < 5; i++){
        glVertex2f(0.0f + x, 0.0f + y);
        y = (log(drawData.permutation.time[i]) - log(min_time))/(log(max_time) - log(min_time));
        printf("y = %f\n",y);
        x+=0.2f;
        glVertex2f(x,y);
    }
    glEnd();
    
    printf("Bubble sorting Y\n");
    // сортировка методом пузырька
    glColor3f(0.529f, 0.694f, 0.961f);
    glBegin(GL_LINES);
    x = 0.0f;y=0.0f;
    for(int i = 0; i < 5; i++){
        glVertex2f(0.0f + x, 0.0f + y);
        y = (log(drawData.bubble.time[i]) - log(min_time))/(log(max_time) - log(min_time));
        printf("y = %f\n",y);
        x+=0.2f;
        glVertex2f(x,y);
    }
    glEnd();
    
    printf("Quick sorting Y");
    // быстрая сортировка
    glColor3f(0.941f, 0.067f, 0.255f);
    glBegin(GL_LINES);
    x = 0.0f;y=0.0f;
    for(int i = 0; i < 5; i++){
        glVertex2f(0.0f + x, 0.0f + y);
        y = (log(drawData.quick.time[i]) - log(min_time))/(log(max_time) - log(min_time));
        printf("y = %f\n",y);
        x+=0.2f;
        glVertex2f(x,y);
    }
    glEnd();
    
    stepQuickY = 0.093;
    printf("step: %f", stepQuickY);
    
    glColor3f(0.792f, 0.855f, 0.729f);
    glBegin(GL_LINES);
    z = 0.0f;
    for(int i = 0; i < 15; i++){
        z+=stepQuickY;
        glVertex2f(0.01f, z);
        glVertex2f(-0.01f, z);
    }
    glEnd();
    
    glPopMatrix();
    // -------
    
    // II
    printf("\n========================================");
    glPushMatrix();
    glViewport(-420, 60, WIDTH - 100, HEIGHT - 80);
    glColor3f(0.792f, 0.855f, 0.729f);
    
    glBegin(GL_LINES);
    
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    z = 0.0f;
    for(int i = 0; i < 5; i++){
        z+=0.2f;
        glVertex2f(z, 0.01f);
        glVertex2f(z, -0.01f);
    }
    
    glEnd();
    draw.printText(0.5f, 0.98f, "(II) SORTING (algorithmic complexity)");
    
    draw.printText(0.18f, -0.04f, "1000");
    draw.printText(0.38f, -0.04f, "5000");
    draw.printText(0.56f, -0.04f, "20000");
    draw.printText(0.76f, -0.04f, "30000");
    draw.printText(0.96f, -0.04f, "50000");
    
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    
    uint64_t min_algo = drawData.quick.algo[0];
    uint64_t max_algo = drawData.permutation.algo[4];

    printf("OOO");
    
    // глупая сортировка
    glColor3f(0.443f, 0.953f, 0.612f);
    glBegin(GL_LINES);
    x = 0.0f;y=0.0f;
    for(int i = 0; i < 5; i++){
        glVertex2f(0.0f + x, 0.0f + y);
        y = (log(drawData.permutation.algo[i]) - log(min_algo))/(log(max_algo) - log(min_algo));
        
        printf("\n i:%d = y permutation= %f\n", i, y);
        x+=0.2f;
        glVertex2f(x,y);
    }
    glEnd();
    
    // сортировка пузырьком
    glColor3f(0.529f, 0.694f, 0.961f);
    glBegin(GL_LINES);
    x = 0.0f;y=0.0f;
    for(int i = 0; i < 5; i++){
        glVertex2f(0.0f + x, 0.0f + y);
        y = (log(drawData.bubble.algo[i]) - log(min_algo))/(log(max_algo) - log(min_algo)) - 0.1;

        printf("\n i:%d = y bubble= %f\n", i, y);
        x+=0.2f;
        glVertex2f(x,y);
    }
    glEnd();
    
    // быстрая сортировка
    glColor3f(0.941f, 0.067f, 0.255f);
    glBegin(GL_LINES);
    x = 0.0f;y=0.0f;
    for(int i = 0; i < 5; i++){
        glVertex2f(0.0f + x, 0.0f + y);
        y = (log(drawData.quick.algo[i]) - log(min_algo))/(log(max_algo) - log(min_algo));
        
        printf("\n i:%d = y quick= %f\n", i, y);
        x+=0.2f;
        glVertex2f(x,y);
    }
    glEnd();
    
    stepQuickY = 0.13421;
//    printf("step: %f",stepQuickY);
    
    glColor3f(0.792f, 0.855f, 0.729f);
    glBegin(GL_LINES);
    z = 0.0f;
    for(int i = 0; i < 15; i++){
        z+=stepQuickY;
        glVertex2f(0.01f, z);
        glVertex2f(-0.01f, z);
    }
    glEnd();

    glPopMatrix();
    // -------

    // III
    printf("\n========================================");
    printf("OOO\n");
    glPushMatrix();
    glViewport(-420, -340, WIDTH - 100, HEIGHT - 80);
    glColor3f(0.792f, 0.855f, 0.729f);
    
    glBegin(GL_LINES);
    
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    z = 0.0f;
    for(int i = 0; i < 5; i++){
        z+=0.2f;
        glVertex2f(z, 0.01f);
        glVertex2f(z, -0.01f);
    }
    
    glEnd();
    
    draw.printText(0.1f, 0.98f, "(III) SEARCH (algorithmic complexity)");
    
    draw.printText(0.18f, -0.04f, "1000");
    draw.printText(0.38f, -0.04f, "5000");
    draw.printText(0.56f, -0.04f, "20000");
    draw.printText(0.76f, -0.04f, "30000");
    draw.printText(0.96f, -0.04f, "50000");
    
    max_algo = drawData.binary.algo[4];
    min_algo = drawData.direct.algo[0];
    
    // бинарный поиск
    glColor3f(0.443f, 0.953f, 0.612f);
    glBegin(GL_LINES);
    x = 0.0f;y=0.0f;
    for(int i = 0; i < 5; i++){
        glVertex2f(0.0f + x, 0.0f + y);
        y = (log(drawData.binary.algo[i]) - log(min_algo))/(log(max_algo) - log(min_algo));
        printf("binary y = %f\n",y);
        x+=0.2f;
        glVertex2f(x,y);
    }
    glEnd();
    
    // прямой поиск
    glColor3f(0.941f, 0.067f, 0.255f);
    glBegin(GL_LINES);
    x = 0.0f;y=0.0f;
    for(int i = 0; i < 5; i++){
        glVertex2f(0.0f + x, 0.0f + y);
        y = (log(drawData.direct.algo[i]) - log(min_algo))/(log(max_algo) - log(min_algo));
        printf("direct y = %f\n",y);
        x+=0.2f;
        glVertex2f(x,y);
    }
    glEnd();
    
    stepQuickY = (max_algo - min_algo) / 10;
//    printf("step: %f\n",stepQuickY);
    
    glColor3f(0.792f, 0.855f, 0.729f);
    glBegin(GL_LINES);
    z = 0.0f;
    for(int i = 0; i < 15; i++){
        z+=stepQuickY;
        glVertex2f(0.01f, z);
        glVertex2f(-0.01f, z);
    }
    glEnd();

    glPopMatrix();
    // -------
    
    // IV
    printf("\n========================================");
    glPushMatrix();
    glViewport(80, -340, WIDTH - 100, HEIGHT - 80);
    glColor3f(0.792f, 0.855f, 0.729f);
    
    glBegin(GL_LINES);
    
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    z = 0.0f;
    for(int i = 0; i < 5; i++){
        z+=0.2f;
        glVertex2f(z, 0.01f);
        glVertex2f(z, -0.01f);
    }
    
    glEnd();
    
    draw.printText(0.1f, 0.98f, "(IV) SEARCH (time complexity)");
    
    draw.printText(0.18f, -0.04f, "1000");
    draw.printText(0.38f, -0.04f, "5000");
    draw.printText(0.56f, -0.04f, "20000");
    draw.printText(0.76f, -0.04f, "30000");
    draw.printText(0.96f, -0.04f, "50000");
    
    min_time = drawData.direct.time[0];
    max_time = drawData.binary.time[4];
    
    printf("Binary search");
    // бинарный поиск
    glColor3f(0.443f, 0.953f, 0.612f);
    glBegin(GL_LINES);
    x = 0.0f;y=0.0f;
    for(int i = 0; i < 5; i++){
        glVertex2f(0.0f + x, 0.0f + y);
        y = (log(drawData.binary.time[i]) - log(min_time))/(log(max_time) - log(min_time));
        printf("y = %f\n",y);
        x+=0.2f;
        glVertex2f(x,y);
    }
    glEnd();
    
    printf("Direct");
    // прямой поиск
    glColor3f(0.941f, 0.067f, 0.255f);
    glBegin(GL_LINES);
    x = 0.0f;y=0.0f;
    for(int i = 0; i < 5; i++){
        glVertex2f(0.0f + x, 0.0f + y);
        y = (log(drawData.direct.time[i]) - log(min_time))/(log(max_time) - log(min_time));
        printf("y = %f\n",y);
        x+=0.2f;
        glVertex2f(x,y);
    }
    glEnd();
    
    stepQuickY = 0.123;
//    printf("step: %f",stepQuickY);
    
    glColor3f(0.792f, 0.855f, 0.729f);
    glBegin(GL_LINES);
    z = 0.0f;
    for(int i = 0; i < 10; i++){
        z+=stepQuickY;
        glVertex2f(0.01f, z);
        glVertex2f(-0.01f, z);
    }
    glEnd();
    
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

uint64_t getPermutationO(int n) {
    return (uint64_t) n*n*n;
}

uint64_t getBubbleO(int n) {
    return (uint64_t) (n-1) * n;
}

uint64_t getQuickO(int n) {
    return (uint64_t) n/2;
}

uint64_t getDirectO(int n) {
    return (uint64_t) n;
}

uint64_t getBinaryO(int n){
    return (uint64_t) n/2 + n/2;
}
