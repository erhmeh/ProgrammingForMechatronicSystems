#include "Ranger.h"
#include "Laser.h"

#define LASER_BAUD_DEFAULT 38400
#define LASER_XOFFSET_DEFAULT 0
#define LASER_OOFFSET_DEFAULT 0
#define LASER_ANGULAR_RES_DEFAULT 10.0
#define LASER_FOV 180
#define LASER_MIN_DIST 0.2
#define LASER_MAX_DIST 8.0

Laser::Laser(){
  baudRate_ = LASER_BAUD_DEFAULT;
  xOffset_ = LASER_XOFFSET_DEFAULT;
  oOffset_ = LASER_OOFFSET_DEFAULT;
  res_ = LASER_ANGULAR_RES_DEFAULT;
  fov_ = LASER_FOV;
  minDist_ = LASER_MIN_DIST;
  maxDist_ = LASER_MAX_DIST;
}

bool Laser::setXOffset(double i){
  return Ranger::setXOffset(i, -10.0, 10.0);
}

bool Laser::setOOffset(double i){
    return Ranger::setOOffset(i);
}

bool Laser::setAngularRes(double i){
  if (i == 10 || i == 30){
    return Ranger::setAngularRes(i);
  }
  else {
    return false;
  }
}
