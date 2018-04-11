#include "shape_functions.h"

// Notice that this funciton doesn't know about Rectangles or Circles, only Shapes!
std::vector<unsigned int> shape_functions::getShapesBoundingPoint(
	const std::vector<Shape*> shapes, double x, double y) {

	// Create vector to store our list of indicies
	std::vector<unsigned int> bounding_shape_indicies;

	for (int i = 0; i < shapes.size(); i++) {
		// For each shape in shapes add the shapes index to the
		// vector if the point is within that shape
		if (shapes.at(i)->pointIsInShape(x, y)) {
			bounding_shape_indicies.push_back(i);
		}
	}
	return bounding_shape_indicies;
}