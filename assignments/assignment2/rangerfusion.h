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
#include "ranger.h"

class RangerFusion
{
protected:
vector<Ranger *> rangers_;
public:
void takeReadings();
vector<vector<double> > rawData_;
vector<double> fusedData_;
char requestedFuseType_;
virtual void setRangers(vector<Ranger *> sensor);
virtual vector<double> getFusedRangeData();
virtual vector<vector<double> > getRawRangeData();
};

#endif // RANGERFUSION_H
