/* Laser.cpp
 * Programming for Mechatronic systems
 * Assignment 2
 *
 * @author: Jamin Early 99133391
 * @date: Week 5-7 Autumn Semester 2018
 */

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
  setBaudRate(LASER_BAUD_DEFAULT);
  setXOffset(LASER_XOFFSET_DEFAULT);
  setOOffset(LASER_OOFFSET_DEFAULT);
  setAngularRes(LASER_ANGULAR_RES_DEFAULT);
  setFov(LASER_FOV);
  setMaxDistance(LASER_MAX_DIST);
  setMinDistance(LASER_MIN_DIST);
}

bool Laser::setAngularRes(double i){
  if (i == 10 || i == 30){
    return Ranger::setAngularRes(i);
  }
  else {
    return false;
  }
}
