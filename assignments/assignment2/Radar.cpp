/* RADAR.cpp
 * Programming for Mechatronic systems
 * Assignment 2
 *
 * @author: Jamin Early 99133391
 * @date: Week 5-7 Autumn Semester 2018
 */

#include "Ranger.h"
#include "Radar.h"
#include <chrono>
#include <random>
#include <iostream>


#define RADAR_BAUD_DEFAULT 38400
#define RADAR_XOFFSET_DEFAULT 0
#define RADAR_OOFFSET_DEFAULT 0
#define RADAR_ANGULAR_RES_DEFAULT 20.0
#define RADAR_FOV 60.0
#define RADAR_MIN_DIST 0.2
#define RADAR_MAX_DIST 16.0

Radar::Radar()
{
  setBaudRate(RADAR_BAUD_DEFAULT);
  setXOffset(RADAR_XOFFSET_DEFAULT);
  setOOffset(RADAR_OOFFSET_DEFAULT);
  setAngularRes(RADAR_ANGULAR_RES_DEFAULT);
  setFov(RADAR_FOV);
  setMaxDistance(RADAR_MAX_DIST);
  setMinDistance(RADAR_MIN_DIST);
}

void Radar::takeReading(){
  scan.clear();
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  default_random_engine generator(seed);
  normal_distribution<double> distribution(6.0,5.0);
  for (int i = 0; i <= (fov_/res_); i++){
    scan[i] = distribution(generator);
    cout << scan[i] << " ";
  }
}

double Radar::readingAtAngle(double angle){

}
