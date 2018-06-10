#ifndef RANGERFUSIONINTERFACE_H
#define RANGERFUSIONINTERFACE_H

#include <vector>
#include <map>
#include <mutex>
#include <condition_variable>

using namespace std;

/*This is a forward declaration of the Ranger class
  It tells the RangerFusionInterface that such a class exists
  but does not specify its details*/
class Ranger;

/*The RangerFusionInterface is a class which specifies the minimum
required interface for your RangerFusion class your ranger fusion
class must inherit from it*/
class RangerFusionInterface
{
public:
    RangerFusionInterface();

    /// Returns a container of fused range readings
    virtual double getFusedRangeData(vector<map<double,double>>& data, chrono::system_clock::time_point& time, mutex& mtx, condition_variable& cv) = 0;

    /// Returns a container of raw/unfused range readings
    virtual vector<double> getRawRangeData(vector<map<double,double>>& data, chrono::system_clock::time_point& time) = 0;

};

#endif // RANGERFUSIONINTERFACE_H
