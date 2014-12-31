//
//  main.c
//  laba3_test
//
//  Created by Sergei Waribrus on 25/12/14.
//  Copyright (c) 2014 Sergei Waribrus. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include "string.h"
#include <math.h>
#include <time.h>

struct lPoint
{
    double fin;
    float angle;
    double glx;
    double gly;
    double x;
    double y;
};

int p_count;
struct lPoint points[10], temp;
int i, j, h;
float angle_min;
float fin_point[2];
float high_point;
float x, y;

void Gift(void)
{
    //Определение первой точки
    angle_min = 15.0; // минимальный угол
    for (j = 0; j < p_count; j++)
    {
        x = points[j].x;
        y = points[j].y;
        points[j].angle = atan2(y, x);
        if (points[j].angle > 0 && points[j].angle <= angle_min)
        {
            temp.x = points[j].x;
            temp.y = points[j].y;
            
            points[j].x = points[0].x;
            points[j].y = points[0].y;
            
            points[0].x = temp.x;
            points[0].y = temp.y;
            
            angle_min = points[j].angle;
        }
    }
    
    //Определение последней точки
    angle_min = 0.0;
    for (j = 1; j < p_count; j++)
    {
        x = points[j].x - points[0].x;
        y = points[j].y - points[0].y;
        if (atan2(y, x) < 0)
            points[j].angle = atan2(y, x) + 6.28;
        else
            points[j].angle = atan2(y, x);
        
        if(points[j].angle > angle_min)
        {
            angle_min = points[j].angle;
            fin_point[0] = points[j].x;
            fin_point[1] = points[j].y;
        }
    }
    
    // Расчет верхней точки по игрику
    high_point = 0.0;
    for (i = 0; i < p_count; i++) {
        if (points[i].y > high_point)
        {
            high_point = points[i].y;
        }
    }
    
    // Сортировка
    h = 0;
    for (i = 0; i < p_count; i++)
    {
        angle_min = 15.0;
        for (j = i + 1; j < p_count; j++)
        {
            if (points[i].y == high_point)  // если текущая точка самая большая по y
                h = 1;
            
            x = points[j].x - points[i].x;
            y = points[j].y - points[i].y;
            points[j].angle = atan2(y,x);   // угол между двумя точками
            
            if (points[j].angle >= 0 && points[j].angle <= angle_min && h == 0)
            {
                temp.x = points[j].x;
                temp.y = points[j].y;
                points[j].x = points[i+1].x;
                points[j].y = points[i+1].y;
                points[i+1].x = temp.x;
                points[i+1].y = temp.y;
                angle_min = points[j].angle;
            }
            
            if(points[j].angle <= 0 && points[j].angle <= angle_min && h == 1)
            {
                temp.x = points[j].x;
                temp.y = points[j].y;
                points[j].x = points[i+1].x;
                points[j].y = points[i+1].y;
                points[i+1].x = temp.x;
                points[i+1].y = temp.y;
                angle_min = points[j].angle;
            }
        }
        
        if(points[i].x == fin_point[0] && points[i].y == fin_point[1])
        {
            h = 3;
            points[0].fin = i+1;
            i = p_count;
        }
    }
}
void Display(void)
{
    glClearColor(0.0,0.0,0.0,0.5);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    for (i = 0; i < p_count; i++)
    {
        points[i].glx = (1.0/300)*(points[i].x-300);
        points[i].gly = (1.0/300)*(points[i].y-300);
    }
    
    glPointSize(3);
    
    glBegin(GL_POINTS);
    
    glColor3ub(255,255,255);
//    glVertex3d(points[0].glx, points[0].gly, 0);
    glColor3ub(255,255,51);
//    glVertex3d((1.0/300)*(fin_point[0]-300), (1.0/300)*(fin_point[1]-300), 0);
    glColor3ub(0,255,0);
    
    for (i = 0; i < points[0].fin; i++)
        glVertex3d(points[i].glx, points[i].gly, 0);
    glColor3ub(255,0,0);
    
    for (i = 0; i < p_count; i++)
        glVertex3d(points[i].glx, points[i].gly, 0);
    
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < points[0].fin; i++)
        glVertex3d(points[i].glx, points[i].gly, 0);
    glEnd();
    
    glutSwapBuffers();
}

void Reshape(GLsizei width, GLsizei height)
{ 
    
} 

void Keyboard(unsigned char key, int x1, int y1) 
{
    srand(time(0));
    
    if(key=='1')
    {

//        for (i = 0; i < p_count; i++)
//        {
//            points[i].x=1+rand()%599+1/rand()%1000;
//            points[i].y=1+rand()%599+1/rand()%1000;
//        }
        p_count = 7;
        points[0].x = 453.0;
        points[0].y = 167.0;
        points[1].x = 558.0;
        points[1].y = 397.0;
        points[2].x = 23.0;
        points[2].y = 471.0;
        points[3].x = 41.0;
        points[3].y = 329.0;
        points[4].x = 134.0;
        points[4].y = 133.0;
        points[5].x = 302.0;
        points[5].y = 419.0;
        points[6].x = 141.0;
        points[6].y = 194.0;
        
        Gift();
        
        for (i=0; i<p_count; i++)
            printf("%d: %f %f\n", i, points[i].x, points[i].y);
        
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(200, 50);
    glutCreateWindow("GIFT");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutIdleFunc(Display);
    glutKeyboardFunc(Keyboard);
    glutMainLoop();
    
    return 0;
}
