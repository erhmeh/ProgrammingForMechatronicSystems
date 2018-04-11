#include "rectangle.h"

Rectangle::Rectangle():
width_(0.0), height_(0.0)
{
    description_="square";
}

void Rectangle::setValues(double width, double height)
{
    width_ = width;
    height_ = height;
    if (width_==height_) {
        description_ = "square";
    } else {
        description_ = "rectangle";
    }
}

void Rectangle::setValues(double side) {
    setValues(side, side);
}

double Rectangle::getArea(void)
{
    return width_ * height_;
}

double Rectangle::getPerimeter(void)
{
    return 2*width_ + 2*height_;
}

bool Rectangle::isPointInShape(double &x, double &y){
    double leftEdge =centre_x_ - 0.5 * width_;
    double rightEdge =centre_x_ + 0.5 * width_;
    double topEdge =centre_y_ - 0.5 * height_;
    double bottomEdge =centre_y_ + 0.5 * height_;

    return (x >= leftEdge && x <= rightEdge &&y >=topEdge && y <= bottomEdge);
}
