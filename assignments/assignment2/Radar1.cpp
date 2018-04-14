/* Radar1.cpp
 * Programming for Mechatronic systems
 * Assignment 2
 *
 * @author: Jamin Early 99133391
 * @date: Week 5-7 Autumn Semester 2018
 */

#include "Ranger.h"
#include "Radar1.h"

#define RADAR1_BAUD_DEFAULT 38400
#define RADAR1_XOFFSET_DEFAULT 0
#define RADAR1_OOFFSET_DEFAULT 0
#define RADAR1_ANGULAR_RES_DEFAULT 20.0
#define RADAR1_FOV 60.0
#define RADAR1_MIN_DIST 0.2
#define RADAR1_MAX_DIST 16.0

Radar1::Radar1()
{
  setBaudRate(RADAR1_BAUD_DEFAULT);
  setXOffset(RADAR1_XOFFSET_DEFAULT);
  setOOffset(RADAR1_OOFFSET_DEFAULT);
  setAngularRes(RADAR1_ANGULAR_RES_DEFAULT);
  setFov(RADAR1_FOV);
  setMaxDistance(RADAR1_MAX_DIST);
  setMinDistance(RADAR1_MIN_DIST);
}
