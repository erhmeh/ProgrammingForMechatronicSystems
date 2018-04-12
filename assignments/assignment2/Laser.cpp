#include "Ranger.h"
#include "Laser.h"

Laser::Laser(){}

bool Laser::setXOffset(double i){
  if(Ranger::setXOffset(i, -10.0, 10.0)){
    return true;
  }
  else{
    return false;
  }
}
