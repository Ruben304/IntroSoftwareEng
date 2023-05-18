#include <iostream>
#include <cmath>
#include "Point2D.h"
#include "Vector2D.h"

using namespace std;

Point2D::Point2D() {
	x = 0.0;
	y = 0.0;
}

Point2D::Point2D(double in_x, double in_y) {
	x = in_x;
	y = in_y;
}

double GetDistanceBetween(Point2D p1, Point2D p2) {
	return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}

ostream& operator << (ostream& out, Point2D p1) {
	out << "(" << p1.x << ", " << p1.y << ")";
	return out;
}

Point2D operator + (Point2D p1, Vector2D v1) {
	return Point2D(p1.x + v1.x, p1.y + v1.y);
}

Vector2D operator - (Point2D p1, Point2D p2) {
	return Vector2D(p1.x - p2.x, p1.y - p2.y);
}