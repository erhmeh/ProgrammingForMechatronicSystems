#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle(double centre_x, double centre_y, double width, double height);
    void setWidthHeight(double width, double height);
    void setWidthHeight(double side);
    double getArea (void);
    double getPerimeter(void);
    bool pointIsInShape(double& x, double& y);
private:
	// In addition to a centre, rectangles have a height and width
    double width_, height_;
};

#endif // RECTANGLE_H
