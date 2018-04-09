#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
public:
    Shape();
    virtual double getArea (void);
    virtual double getPerimeter(void);
    virtual bool isPointInShape(double& x, double& y);
    std::string getDescription();
protected:
    double centre_x_, centre_y_;
    std::string description_;
};

#endif // SHAPE_H
