/* rangerfusion.h
 * Programming for Mechatronic systems
 * Assignment 2
 *
 * @author: Jamin Early 99133391
 * @date: Week 5-7 Autumn Semester 2018
 */


#ifndef RANGERFUSION_H
#define RANGERFUSION_H

#include <iostream>
#include <vector>
#include "rangerfusioninterface.h"

class RangerFusion
{
protected:
  vector<vector<vector<double> >* > allScans_;
public:
    vector<double> *sensor1_;
    vector<double> *sensor2_;
    vector<double> *sensor3_;
    RangerFusion();
    virtual void setRangers(vector<vector<double> > *rangers) = 0;
    virtual vector<double> getFusedRangeData() = 0;
    virtual vector<vector<double> > getRawRangeData() = 0;
};

#endif // RANGERFUSION_H
