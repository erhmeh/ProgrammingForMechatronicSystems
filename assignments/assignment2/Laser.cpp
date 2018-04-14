#include "Ranger.h"
#include "Laser.h"

#define LASER_BAUD_DEFAULT 38400
#define LASER_XOFFSET_DEFAULT 0
#define LASER_OOFFSET_DEFAULT 0
#define LASER_FOV 180

Laser::Laser(){
  baudRate_ = LASER_BAUD_DEFAULT;
  xOffset_ = LASER_XOFFSET_DEFAULT;
  oOffset_ = LASER_OOFFSET_DEFAULT;
  fov_ = LASER_FOV;
}

bool Laser::setXOffset(double i){
  return Ranger::setXOffset(i, -10.0, 10.0);
}

bool Laser::setOOffset(double i){
  return Ranger::setOOffset(i);
}
