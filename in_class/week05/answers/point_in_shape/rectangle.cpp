#include "rectangle.h"

Rectangle::Rectangle(): Rectangle(0.0, 0.0, 0.0, 0.0)
{
}

Rectangle::Rectangle(double centre_x, double centre_y, double width, double height) :
    Shape(centre_x, centre_y), width_(width), height_(height)
{
}

void Rectangle::setWidthHeight(double width, double height)
{
    width_ = width;
    height_ = height;
}

void Rectangle::setWidthHeight(double side) {
    setWidthHeight(side, side);
}

double Rectangle::getArea(void)
{
    return width_ * height_;
}

double Rectangle::getPerimeter(void)
{
    return 2*width_ + 2*height_;
}

bool Rectangle::pointIsInShape(double& x, double& y)
{
    // x is positive to the left
    // y is positive down
    double left_edge = centre_x_ - 0.5 * width_;
    double right_edge = centre_x_ + 0.5 * width_;
    double top_edge = centre_y_ - 0.5 * height_;
    double bottom_edge = centre_y_ + 0.5 * height_;

    // Check that the query point lies in between the rectangle edges
    return (x >= left_edge && x <= right_edge &&
            y >= top_edge && y <= bottom_edge);
}
