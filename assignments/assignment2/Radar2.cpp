/* Radar1.cpp
 * Programming for Mechatronic systems
 * Assignment 2
 *
 * @author: Jamin Early 99133391
 * @date: Week 5-7 Autumn Semester 2018
 */

#include "Ranger.h"
#include "Radar2.h"

#define RADAR2_BAUD_DEFAULT 38400
#define RADAR2_XOFFSET_DEFAULT 0
#define RADAR2_OOFFSET_DEFAULT 0
#define RADAR2_ANGULAR_RES_DEFAULT 20.0
#define RADAR2_FOV 60.0
#define RADAR2_MIN_DIST 0.2
#define RADAR2_MAX_DIST 16.0

Radar2::Radar2()
{
  setBaudRate(RADAR2_BAUD_DEFAULT);
  setXOffset(RADAR2_XOFFSET_DEFAULT);
  setOOffset(RADAR2_OOFFSET_DEFAULT);
  setAngularRes(RADAR2_ANGULAR_RES_DEFAULT);
  setFov(RADAR2_FOV);
  setMaxDistance(RADAR2_MAX_DIST);
  setMinDistance(RADAR2_MIN_DIST);
}
