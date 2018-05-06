#include "shape.h"

Shape::Shape():
    description_("unknown shape")
{
}

double Shape::getArea()
{
    // We have no way of calculating the area of an arbitrary shape
    return -1;
}

double Shape::getPerimeter()
{
    // We have no way of calculating the perimeter of an arbitrary shape
    return -1;
}



std::string Shape::getDescription()
{
    return description_;
}
