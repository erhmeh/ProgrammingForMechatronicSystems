#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>

class Rectangle
{
public:
    Rectangle();
    void setValues(double width, double height);
    void setValues(double side);
    double getArea (void);
    double getPerimeter(void);
    std::string getDescription();
private:
    double width_, height_;
    std::string description_;
};

#endif // RECTANGLE_H
