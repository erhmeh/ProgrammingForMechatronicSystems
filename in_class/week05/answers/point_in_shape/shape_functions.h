#include <vector>
#include "shape.h"

// Lets create a namespace that could contain all our functions that work with shapes
namespace shape_functions {
	
// Returns the indices of all shapes that the point x, y lies within
// Notice that this funciton doesn't know about Rectangles or Circles, only Shapes!
std::vector<unsigned int> getShapesBoundingPoint(
	const std::vector<Shape*> shapes, double x, double y);

}