#include "rangerfusion.h"
#include "ranger.h"

///Constructor that accepts a string for fusion method
RangerFusion::RangerFusion(string fusMeth): fuseRate_(5){
    if(checkFuseMeth(fusMeth)){
        fuseMethod_ = fusMeth;
    }
    else {
        fuseMethod_ = "Min";
    }
}
///Check selected fusion method
bool RangerFusion::checkFuseMeth(string fusMeth){
    if (fusMeth.compare("Min")==0||fusMeth.compare("min")==0){
        fusNum_=0;
        return 1;
    }
    else if(fusMeth.compare("Max")==0||fusMeth.compare("max")==0){
        fusNum_=1;
        return 1;
    }
    else if (fusMeth.compare("Avg")==0||fusMeth.compare("avg")==0){
        fusNum_=2;
        return 1;
    }
    else {
        return 0;
    }
}
/*Extracts data for current time key of input map
  then fuses the data using specified fuse method*/
double RangerFusion::getFusedRangeData(vector<map<double,double>>& data, chrono::system_clock::time_point& time, mutex& mtx, condition_variable& cv){
    this_thread::sleep_for (chrono::seconds(1/fuseRate_));
    unique_lock<mutex> lck(mtx);
    vector<double> rawData = getRawRangeData(data, time);
    lck.unlock();
    double fusedData = fuseData(rawData);
    return fusedData;
}
///Function to collect the raw sensor data
vector<double> RangerFusion::getRawRangeData(vector<map<double,double>>& data, chrono::system_clock::time_point& time){
    vector<double> rawData;
    int i = 0;
    chrono::system_clock::duration currentTime = time.time_since_epoch();
    for(auto& sensorItr : data){
        ///Checks if map location has data
        if(sensorItr[currentTime.count()]!=0){
            rawData[i]=sensorItr[currentTime.count()];
        }
        ///Extrapolates from previous data if no data
        else {
            rawData[i] = extrapolate(sensorItr);
        }
        i++;
    }
    return rawData;
}
///Fuse sensor data based on selected method
double RangerFusion::fuseData(vector<double> data){
    double value;
    switch(fusNum_){
        case 0 : value = *min_element(data.begin(), data.end());
            break;
        case 1 : value = *max_element(data.begin(), data.end());
            break;
        case 2 : for(auto& dataSize : data){
                value += dataSize;
            }
            value = value/data.size();
            break;
    }
    return value;
}
///Extrapolates current data from last two data points in map
double RangerFusion::extrapolate(map<double,double> data){
    vector<double> lastTwo;
    map<double,double>::reverse_iterator rit;
    int i = 0;
    for(rit=data.rbegin(); rit!=data.rbegin(); ++rit){
        lastTwo[i] = rit->second;
        i++;
    }
    return (lastTwo[0]+lastTwo[0]-lastTwo[1]);
}
