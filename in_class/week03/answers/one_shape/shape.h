#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
public:
    Shape();
    double getArea (void);
    double getPerimeter(void);
    std::string getDescription();
protected:
    std::string description_;
};

#endif // SHAPE_H
