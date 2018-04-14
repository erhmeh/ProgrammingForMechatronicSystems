/* Ranger.cpp
 * Programming for Mechatronic systems
 * Assignment 2
 *
 * @author: Jamin Early 99133391
 * @date: Week 5-7 Autumn Semester 2018
 */

#include "Ranger.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

Ranger::Ranger(){}

bool Ranger::setXOffset(double i, int min, int max){
    if (i <= max && i >= min){
      xOffset_ = i;
      return true;
    }
    else {
      return false;
    }
}

double Ranger::getXOffset(){
  return xOffset_;
}

bool Ranger::setOOffset(double i){
  if (i >= -180 && i <= 180){
    oOffset_ = i;
    return true;
  }
  else{
    return false;
  }
}

double Ranger::getOOffset(){
  return oOffset_;
}

bool Ranger::setBaudRate(int i){
  if (i == 38400 || i == 115200){
    baudRate_ = i;
    return true;
  }
  else {
    return false;
  }
}

int Ranger::getBaudRate(){
  return baudRate_;
}

bool Ranger::setTtyACM(int i){
  if (i == 0 || i == 1 || i == 2){
    ttyACM_ = i;
    return true;
  }
  else{
    return false;
  }
}

int Ranger::getTty(){
  return ttyACM_;
}

double Ranger::getFov(){
  return fov_;
}

double Ranger::getMinDistance(){
  return minDist_;
}

double Ranger::getMaxDistance(){
  return maxDist_;
}

bool Ranger::setAngularRes(double i){
  if (i != 0){
    res_ = i;
    return true;
  }
  else{
    return false;
  }
}

double Ranger::getAngularRes(){
  return res_;
}
