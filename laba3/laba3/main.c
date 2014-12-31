//
//  main.c
//  laba3
//
//  Created by Sergei Waribrus on 10/12/14.
//  Copyright (c) 2014 Sergei Waribrus. All rights reserved.
//

#include <stdio.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include "string.h"
#include <math.h>
#include <time.h>

#include "file.h"
#include "draw.h"
#include "point.h"

const int WIDTH = 1000;
const int HEIGHT = 800;

int n;
struct lPoint mas[50];

int convex_hull[50];
int ch_i;

int star_polygon[50];

float OrientTriangl2(struct lPoint p1, struct lPoint p2, struct lPoint p3)
{
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
}

int isInside(struct lPoint p1, struct lPoint p, struct lPoint p2)
{
    return ( p1.x <= p.x && p.x <= p2.x &&
            p1.y <= p.y && p.y <= p2.y);}

float rotate(struct lPoint A, struct lPoint B, struct lPoint C)
{
    return (B.x-A.x)*(C.y-B.y)-(B.y-A.y)*(C.x-B.x);
}

void StarPolygon()
{
    // Заполним конечный полигон дефолтными значениями
    for (int i = 0; i < n; i++) {
        star_polygon[i] = i;
    }
    
    
    // Найдем наименьшую точку по Y
    for (int i = 1; i < n; i++) {
        if (mas[star_polygon[i]].y < mas[star_polygon[0]].y) {
            int temp = star_polygon[i];
            star_polygon[i] = star_polygon[0];
            star_polygon[0] = temp;
        }
    }
    // в нулевом индексе хранится номер элемента из массива mas который самый меньший по y
    
    
    // Сортировка вставками
    for (int i = 2; i < n; i++) {
        int j = i;
        while (j > 1 && (rotate(mas[star_polygon[0]],
                                mas[star_polygon[j - 1]],
                                mas[star_polygon[j]])) < 0) {
            int temp = star_polygon[j];
            star_polygon[j] = star_polygon[j-1];
            star_polygon[j-1] = temp;
            j = j - 1;
        }
    }
    
    star_polygon[n] = star_polygon[0];
}

void ConvexHullJarvis()
{
    // находим самую левую из самых нижних
    int base = 0;
    for (int i=1; i < n; i++)
    {
        if (mas[i].y < mas[base].y)
            base = i;
        else
            if (mas[i].y == mas[base].y &&
                mas[i].x <  mas[base].x)
                base = i;
    }
    // эта точка точно входит в выпуклую оболочку
    ch_i = 0;
    convex_hull[ch_i] = base;
    
    
    int first = base;
    int cur = base;
    do
    {
        int next = (cur + 1) % n;
        for (int i=0; i<n; i++)
        {
            float sign = rotate(mas[cur], mas[next], mas[i]);
            // точка mas[i] находится правее прямой ( mas[cur], mas[next] )
            if (sign > 0)
                next = i;
            // точка лежит на прямой, образованной точками  mas[cur], mas[next]
            else if (sign == 0)
            {
                // точка mas[i] находится дальше, чем mas[next] от точки mas[cur]
                if (isInside(mas[cur], mas[next], mas[i]))
                    next = i;
            }
        }
        cur = next;
        
        ch_i++;
        convex_hull[ch_i] = next;
        
    }
    while (cur != first);
}

void Draw(void);
void Reshape(int w, int h);

int main(int argc, const char * argv[]) {
    srand(time(0));
    
    n = 7;
    file.writeRandomFile("/tmp/laba3_7.td", n);
    file.readFile("/tmp/laba3_7.td", &mas[0], n);
    
    ConvexHullJarvis();
    StarPolygon();
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(200, 50);
    glutCreateWindow("Laba 3");
    
    glutDisplayFunc(Draw);
    glutReshapeFunc(Reshape);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    
    return 0;
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
    
    glPointSize(5.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);

    for (int i = 0; i < n; i++) {
        printf("%d: %f, %f \n", i, mas[i].x, mas[i].y);
        glVertex2f(mas[i].x, mas[i].y);
    }
    
    printf("\n\n");
    glEnd();
    
    for (int i = 0; i < n; i++) {
        char str[10];
        sprintf(str, "%d", i);
        draw.printText(mas[i].x, mas[i].y-0.05, str);
    }
    
    glColor3f(0.0f, 0.7f, 1.0f);
    glBegin(GL_LINE_LOOP);
    
//    for (int i = 0; i < n; i++) {
//        glVertex2f(mas[i].x, mas[i].y);
//    }
    for (int i = 0; i < ch_i + 1; i++) {
        printf("%d: %f %f\n", convex_hull[i], mas[convex_hull[i]].x, mas[convex_hull[i]].y);
        glVertex2f(mas[convex_hull[i]].x, mas[convex_hull[i]].y);
    }
    
//    for (size_t i = 0; i < n; i++) {
//        printf("%d: %f %f\n", star_polygon[i], mas[star_polygon[i]].x, mas[star_polygon[i]].y);
//        glVertex2f(mas[star_polygon[i]].x, mas[star_polygon[i]].y);
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
//    draw.printText(0.7f, 0.98f, "gift");
    
    glPointSize(5.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    
    for (int i = 0; i < n; i++) {
//        printf("%d: %f, %f \n", i, mas[i].x, mas[i].y);
        glVertex2f(mas[i].x, mas[i].y);
    }
    
    printf("\n\n");
    glEnd();
    
    for (int i = 0; i < n; i++) {
        char str[10];
        sprintf(str, "%d", i);
        draw.printText(mas[i].x, mas[i].y-0.05, str);
    }
    
    glColor3f(0.0f, 0.7f, 1.0f);
    glBegin(GL_LINE_LOOP);
    
//    for (int i = 0; i < ch_i + 1; i++) {
//        printf("%d: %f %f\n", convex_hull[i], mas[convex_hull[i]].x, mas[convex_hull[i]].y);
//        glVertex2f(mas[convex_hull[i]].x, mas[convex_hull[i]].y);
//    }
    
    for (size_t i = 0; i < n; i++) {
        printf("%d: %f %f\n", star_polygon[i], mas[star_polygon[i]].x, mas[star_polygon[i]].y);
        glVertex2f(mas[star_polygon[i]].x, mas[star_polygon[i]].y);
    }
    
    glEnd();
    
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
    
    draw.printText(0.7f, 0.98f, "");
    
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
    draw.printText(0.8f, 0.98f, "");
    
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