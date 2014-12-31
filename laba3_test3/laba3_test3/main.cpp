//
//  main.cpp
//  laba3_test3
//
//  Created by Sergei Waribrus on 26/12/14.
//  Copyright (c) 2014 Sergei Waribrus. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    int x,y;
    point(){}
    point(int X, int Y)
    {
        x = X;
        y = Y;
    }
};
bool operator != (const point &a, const point &b)
{
    return !(a.x == b.x && a.y == b.y);
}
double dist (const point &a, const point &b)
{
    return sqrt( 0.0 + (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int n;
vector<point> mas;
vector<int> convex_hull;
double P;
void input()
{
    cout << "Enter n";
    cin>>n;
    mas.resize(n);
    for (int i=0;i<n;i++)
        scanf("%d %d", &mas[i].x, &mas[i].y);
}
double eps = 1e-8;
double Fabs(const double &a)
{
    if (a<0)
        return -a;
    return a;
}
bool Equal(const double &a, const double &b)
{
    return Fabs(a-b) <= eps;
}
bool More(const double &a, const double &b)
{
    return !Equal(a,b) && a > b;
}
bool Less(const double &a, const double &b)
{
    return !Equal(a,b) && a < b;
}
double CosAngle(const point &prev,const point &cur,const point &next)
{
    point v1(next.x - cur.x, next.y - cur.y);
    point v2(prev.x - cur.x, prev.y - cur.y);
    return (v1.x * v2.x + v1.y * v2.y) / (dist(prev,cur) * dist(cur,next));
}
void ConvexHullJarvis(const vector<point> &mas, vector<int> &convex_hull)
{
    // находим самую левую из самых нижних
    int base = 0;
    for (int i=1;i<n;i++)
    {
        if (mas[i].y < mas[base].y)
            base = i;
        else
            if (mas[i].y == mas[base].y &&
                mas[i].x <  mas[base].x)
                base = i;
    }
    // эта точка точно входит в выпуклую оболочку
    convex_hull.push_back(base);
    
    point first = mas[base];
    point cur = first;
    point prev = point(first.x - 1, first.y);
    do
    {
        double minCosAngle = 1e9; // чем больше угол, тем меньше его косинус
        double maxLen = 1e9;
        int next = -1;
        for (int i=0;i<n;i++)
        {
            double curCosAngle = CosAngle(prev, cur, mas[i]);
            if (Less(curCosAngle,minCosAngle))
            {
                next = i;
                minCosAngle = curCosAngle;
                maxLen = dist(cur,mas[i]);
            }
            else if (Equal(curCosAngle, minCosAngle))
            {
                double curLen = dist(cur,mas[i]);
                if (More(curLen,maxLen))
                {
                    next = i;
                    maxLen = curLen;
                }
            }
        }
        prev = cur;
        cur = mas[next];
        convex_hull.push_back(next);
    }
    while (cur != first);
}
void solve()
{
    ConvexHullJarvis(mas,convex_hull);
    
    for (size_t i=0;i<convex_hull.size()-1;i++) {
        P += dist(mas[convex_hull[i]],mas[convex_hull[i+1]]);
        printf("%d %d %d", i, mas[i].x, mas[i].y);
    }
}
void output()
{
    printf("%0.1f",P);
}


int main(int argc, const char * argv[]) {
    input();
    solve();
    output();
    
    return 0;
}
