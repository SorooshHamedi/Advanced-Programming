#include "MathFunctions.hpp"
#include <cmath>
#include <iostream>

float distance(Point a, Point b)
{
    a-=b;
    return sqrt(pow(a.x,2)+pow(a.y,2));
}

float size(Point a)
{
    return sqrt( pow(a.x,2) + pow(a.y,2));
}

float size(GeometricVector a)
{
    return sqrt( pow(a.x,2) + pow(a.y,2));
}

GeometricVector multiply(GeometricVector v, Point p)
{
    return GeometricVector(v.x*p.x, v.x*p.y);
}

GeometricVector multiply(GeometricVector p, float c)
{
    return GeometricVector(p.x*c, p.y*c);
}

GeometricVector subtract(GeometricVector a, GeometricVector b)
{
    return GeometricVector(a.x-b.x, a.y-b.y);
}
Point abs(Point u)
{
    return Point(abs(u.x), abs(u.y));
}

float dotProduct(Point a, Point b)
{
    return (float)(a.x*b.x) + (float)(a.y*b.y);
}

float dotProduct(GeometricVector a, Point b)
{
    return (a.x*b.x) + (a.y*b.y);
}

GeometricVector multiply(Point p, float c)
{
    return GeometricVector(p.x*c, p.y*c);
}
