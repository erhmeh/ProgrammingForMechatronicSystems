/* rangerfusion.cpp
 * Programming for Mechatronic systems
 * Assignment 2
 *
 * @author: Jamin Early 99133391
 * @date: Week 5-7 Autumn Semester 2018
 */

#include <iostream>
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "ranger.h"
#include "rangerfusion.h"
#include "rangerfusioninterface.h"

using namespace std;

void RangerFusion::setRangers(vector<double> *rangers){
  allScans_.insert(allScans_.end(), rangers);
}

vector<double> RangerFusion::getFusedRangeData(){
}

vector<vector<double> > RangerFusion::getRawRangeData(){

}
