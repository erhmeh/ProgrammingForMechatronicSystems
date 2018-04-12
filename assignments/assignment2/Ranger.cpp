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
      xOffset = i;
      return true;
    }
    else {
      return false;
    }
}

bool Ranger::setOOffset(double i){
  if (i >= -180 && i <= 180){
    oOffset = i;
    return true;
  }
  else{
    return false;
  }
}

bool Ranger::setBaudRate(int i){
  if (i == 38400 || i == 115200){
    baudRate = i;
    return true;
  }
  else {
    return false;
  }
}

bool Ranger::setTtyACM(int i){
  if (i == 0 || i == 1 || i == 2){
    ttyACM = i;
    return true;
  }
  else{
    return false;
  }
}

int Ranger::getTty(){
  return ttyACM;
}
