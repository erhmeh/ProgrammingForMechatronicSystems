#ifndef SHAPE_H
#define SHAPE_H

#include <string>

// Shape is abstract meaning we cannot create objects of type Shape
// We do this because it doesn't make sense to define a generic shape
// For example we cannot know how to compute the area of a generic shape
class Shape
{
public:
    Shape();
    Shape(double centre_x, double centre_y);
    // Methods to get area and perimeter are pure virtual
    // They do not have an implementation for Shape
    virtual double getArea (void)= 0;
    virtual double getPerimeter(void) = 0;

    // Checks if the query point lies within the bounds of the shape
    // Pure virtual because we need to know more about the shape to 
    // answer this question
    virtual bool pointIsInShape(double& x, double& y) = 0;

    // Set the shapes centre
    // This function is implemented for Shape
    void setCentre(double x, double y);

protected:
	// The only data shapes have in common is their location/centre
	double centre_x_, centre_y_;
};

#endif // SHAPE_H
