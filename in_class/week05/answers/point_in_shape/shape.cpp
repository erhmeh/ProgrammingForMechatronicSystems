#include "shape.h"

// Not much here because this class is VERY abstract

Shape::Shape(): Shape(0.0, 0.0)
{
}

Shape::Shape(double centre_x, double centre_y): centre_x_(centre_x), centre_y_(centre_y)
{
}

void Shape::setCentre(double x, double y)
{
	centre_x_ = x;
	centre_y_ = y;
}