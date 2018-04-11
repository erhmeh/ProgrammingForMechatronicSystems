#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
public:
    Circle();
    Circle(double centre_x, double centre_y, double radius);
    void setRadius(double radius);
    double getArea (void);
    double getPerimeter(void);
    bool pointIsInShape(double& x, double& y);
private:
	// In addition to a centre, circles have a radius
    double radius_;
};

#endif // CIRCLE_H
