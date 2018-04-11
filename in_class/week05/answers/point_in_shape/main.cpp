#include <iostream>
#include <vector>
#include "shape.h"
#include "shape_functions.h"
#include "rectangle.h"
#include "circle.h"

int main () {
    // Create some rectangles
    Rectangle r1(4.0, 4.0, 2.0, 3.0), r2(2.0, 5.0, 3.0, 1.5);

    // Create some circles
    Circle c1(4.5, 3.5, 2.0), c2(4.0, 4.5, 1.5);

    // Put pointers to all the shapes in a vector
    std::vector<Shape*> shapes {&r1, &r2, &c1, &c2};

    // Accept user input for the query point
    double query_x, query_y;
    std::cout << "Enter your query point x followed by y: ";
    std::cin >> query_x >> query_y;

    auto bounding_shapes = shape_functions::getShapesBoundingPoint(shapes, query_x, query_y);

    if (bounding_shapes.size() > 0) {
        std::cout << "Shapes ";
        for (auto shape_idx : bounding_shapes) {
            std::cout << shape_idx << " ";
        }
        std::cout << "contain the point (" <<
            query_x << ", " << query_y << ")" << std::endl;
    } else {
        std::cout << "No shapes contain the point (" <<
            query_x << ", " << query_y << ")" << std::endl;
    }

    return 0;
}
