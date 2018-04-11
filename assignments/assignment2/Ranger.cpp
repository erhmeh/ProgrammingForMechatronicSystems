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

Ranger::setXOffset(double i){
    if (i <= 10 && i >= -10){
      xOffset = i;
      return true;
    }
    else {
      return false;
    }
}
