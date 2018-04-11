#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle();
    void setValues(double width, double height);
    void setValues(double side);
    double getArea (void);
    double getPerimeter(void);
    virtual bool isPointInShape(double& x, double& y);
private:
    double width_, height_;
};

#endif // RECTANGLE_H
