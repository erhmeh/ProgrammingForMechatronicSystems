#include "Rectangle.h"

double Rectangle::area(void){
        return (width_*height_);
}

double Rectangle::perimeter(void){
        return (2*width_ + 2*height_);
}

bool Rectangle::setWidthHeight(double i, double j){
        if(i > 0 && j > 0){
        width_ = i;
        height_ = j;
        return true;
      }
      else {
        return false;
      }
}

bool Rectangle::setWidthHeight(double i){
        if(i > 0){
        width_ = i;
        height_ = i;
        return true;
      }
      else {
        return false;
      }
}

double Rectangle::getHeight(){
  return height_;
}

double Rectangle::getWidth(){
  return width_;
}
