/********************************************************************************
 * Week 02 - Classes Prework
 *
 * The class "Rectangle" has three functions. These member functions are called
 * setWidthHeight (accepts two int arguments and is a setter), area (does not accept
 * any arguments and returns an int) and perimeter (does not accept any argmuments
 * and returns an int). Access specifies are public and private and limit the
 * access to data members. A setter method is required to set the rectangles width
 * and height as these data members are private and cannot be modified elsewhere.
 * It is best practice to keep classes in their own files however I have kept it
 * together for ease of use.
 *
 *********************************************************************************/

#include "Rectangle.h"
#include "RandomArray.h"
#include <random>
#include <cstdlib>
#include <iostream>
using namespace std;

// Main
int main() {
        Rectangle squareBoi;
        RandomArray randBoi;
        double width;
        double height;
        int seed;
        int arraySize;
        while (true) {
                char option;
                std::cout << "Please choose the Class to demonstrate. For rectangle press 'r', for square press 's', for array 'a' or for sum of rectangles 's'\n" << std::endl;
                cin >> option;
                switch(option) {
                case 'r':
                        std::cout << "Please enter an integer value for height. " << std::endl;
                        cin >> height;
                        std::cout << "Please enter an integer value for width. " << std::endl;
                        cin >> width;
                        if (squareBoi.setWidthHeight(width, height)){
                        std::cout << "\n With a width of " << width << " and a height of " << height << " the area is " << squareBoi.area() << " and the perimeter is "<< squareBoi.perimeter() << " \n\n" << std::endl;
                      }
                      else{
                        cout << "Invalid width or height" << endl;
                      }
                        break;
                case 's':
                                std::cout << "Please enter an integer value for height & width. " << std::endl;
                                cin >> height;
                                if (squareBoi.setWidthHeight(height)){
                                std::cout << "\n With a width of and a height of " << height << " the area is " << squareBoi.area() << " and the perimeter is "<< squareBoi.perimeter() << " \n\n" << std::endl;
                              }
                              else{
                                cout << "Invalid width or height" << endl;
                              }
                                break;
                case 'a':
                        std::cout << "Please enter an integer value for the seed. " << std::endl;
                        cin >> seed;
                        std::cout << "Please enter an integer value for the array size. " << std::endl;
                        cin >> arraySize;
                        randBoi.setSeed(seed);
                        randBoi.setArraySize(arraySize);
                        randBoi.generate();
                        for(int i = 0; i < arraySize; i++) {
                                std::cout << "[" << randBoi.randDoub_[i] << "] ";
                        }
                        std::cout << "\n" << std::endl;
                        break;
                }
        }
        return 0;
}
