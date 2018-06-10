#ifndef RANGERFUSION_H
#define RANGERFUSION_H

#include "rangerfusioninterface.h"

#include <string>
#include <algorithm>
#include <chrono>

class RangerFusion : public RangerFusionInterface{

public:
    RangerFusion(string fusMeth);

    double getFusedRangeData(vector<map<double,double>> &data, chrono::_V2::system_clock::time_point &time, mutex &mtx, condition_variable &cv);
    vector<double> getRawRangeData(vector<map<double,double>>& data, chrono::_V2::system_clock::time_point &time);
private:
    bool checkFuseMeth(string fusMeth);
    double fuseData(vector<double> data);
    double extrapolate(map<double, double> data);
    string fuseMethod_;
    int fusNum_, fuseRate_;
};

#endif // RANGERFUSION_H
