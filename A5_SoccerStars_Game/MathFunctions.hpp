#ifndef _SOCCER_STARS_FUNCTIONS_HPP_
#define _SOCCER_STARS_FUNCTIONS_HPP_
#include "rsdl.hpp"
#include "GeometricVector.hpp"
float distance(Point a, Point b);
float size(Point a);
float size(GeometricVector a);
GeometricVector multiply(GeometricVector v, Point p);
GeometricVector multiply(GeometricVector p, float c);
GeometricVector multiply(Point p, float c);
GeometricVector subtract(GeometricVector a, GeometricVector b);
Point abs(Point x);
float dotProduct(Point a, Point b);
float dotProduct(GeometricVector a, Point b);

#endif