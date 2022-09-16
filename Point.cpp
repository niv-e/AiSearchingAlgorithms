#include "Point.h"
#include "math.h"

Point::Point(int x, int y)
{
	_x = x;
	_y = y;
}
Point::~Point()
{

}

double Point::CalculateEucludeanDistaceSqure(Point first, Point second)
{
	return pow((first.GetX() - second.GetX()), 2) + pow((first.GetY() - second.GetY()), 2);
}

