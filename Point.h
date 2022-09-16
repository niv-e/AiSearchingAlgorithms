#pragma once
#include "math.h"

class Point
{
private:
	int _x;
	int _y;

public:
	Point(int x, int y);

	~Point();

	int GetX() { return _x; };

	int GetY() { return _y; };

	double CalculateEucludeanDistaceSqure(Point first, Point second);
};