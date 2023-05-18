#ifndef T2POINT2D_H
#define T2POINT2D_H
#include <iostream>
#include "Vector2D.h"

using namespace std;

class Point2D {
	public:
		double x, y;
		
		Point2D();
		Point2D(double, double);
};

double GetDistanceBetween(Point2D, Point2D);

ostream& operator << (ostream&, Point2D);
Point2D operator + (Point2D, Vector2D);
Vector2D operator - (Point2D, Point2D);

#endif