#include "circle.h"
#include <cmath>

Circle::Circle():
	Circle(0.0, 0.0, 0.0)
{
}

Circle::Circle(double centre_x, double centre_y, double radius):
	Shape(centre_x, centre_y), radius_(radius)
{
}

void Circle::setRadius(double radius) {
	radius_ = radius;
}

double Circle::getArea (void) {
	return M_PI * std::pow(radius_, 2);
}

double Circle::getPerimeter(void) {
	return 2 * M_PI * radius_;
}

bool Circle::pointIsInShape(double& x, double& y) {
	double distance_from_centre = std::sqrt(std::pow(x - centre_x_, 2.0) + std::pow(y - centre_y_, 2.0));
	return distance_from_centre <= radius_;
}