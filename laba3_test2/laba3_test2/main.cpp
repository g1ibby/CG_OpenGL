//
//  main.cpp
//  laba3_test2
//
//  Created by Sergei Waribrus on 26/12/14.
//  Copyright (c) 2014 Sergei Waribrus. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>


struct lPoint
{
    int x;
    int y;
};

double dist (const lPoint &a, const lPoint &b)
{
    return sqrt( 0.0 + (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int n;
struct lPoint mas[50];
int convex_hull[50];
int ch_i;

int star_polygon[50];

void input()
{
    n = 7;

    mas[0].x = 2; mas[0].y = 5;
    mas[1].x = 5; mas[1].y = 2;
    mas[2].x = 5; mas[2].y = 3;
    mas[3].x = 12; mas[3].y = 3;
    mas[4].x = 14; mas[4].y = 9;
    mas[5].x = 8; mas[5].y = 8;
    mas[6].x = 1; mas[6].y = 9;
}

int OrientTriangl2(const lPoint &p1,const lPoint &p2, const lPoint &p3)
{
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
}

bool isInside(const lPoint &p1, const lPoint &p, const lPoint &p2)
{
    return ( p1.x <= p.x && p.x <= p2.x &&
            p1.y <= p.y && p.y <= p2.y);
}

int rotate(const lPoint &A, const lPoint &B, const lPoint &C)
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
        while (j > 1 && (rotate(mas[star_polygon[0]], mas[star_polygon[j - 1]], mas[star_polygon[j]])) < 0) {
            int temp = star_polygon[j];
            star_polygon[j] = star_polygon[j-1];
            star_polygon[j-1] = temp;
            j = j - 1;
        }
    }
    
    star_polygon[n-1] = star_polygon[0];
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
            int sign = OrientTriangl2(mas[cur], mas[next], mas[i]);
            // точка mas[i] находится левее прямой ( mas[cur], mas[next] )
            if (sign < 0) // обход выпуклой оболочки против часовой стрелки
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

int main(int argc, const char * argv[]) {
 
    input();
    ConvexHullJarvis();

    for (size_t i = 0; i < ch_i + 1; i++) {
        printf("%d: %d %d\n", convex_hull[i], mas[convex_hull[i]].x, mas[convex_hull[i]].y);
    }
    
    printf("\n\n");

    StarPolygon();
    for (size_t i = 0; i < n; i++) {
        printf("%d: %d %d\n", star_polygon[i], mas[star_polygon[i]].x, mas[star_polygon[i]].y);
    }
    
    return 0;
}

