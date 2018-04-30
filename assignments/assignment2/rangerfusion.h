/* rangerfusion.h
 * Programming for Mechatronic systems
 * Assignment 2
 *
 * @author: Jamin Early 99133391
 * @date: Week 5-7 Autumn Semester 2018
 */


#ifndef RANGERFUSION_H
#define RANGERFUSION_H

#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include "rangerfusioninterface.h"

class RangerFusion
{
protected:
  vector<vector<double> * > allScans_;
public:
    char requestedFuseType_;
    vector<double> *sensor2_;
    vector<double> *sensor3_;
    virtual void setRangers(vector<double> *rangers);
    virtual vector<double> getFusedRangeData();
    virtual vector<vector<double> > getRawRangeData();
};

#endif // RANGERFUSION_H
