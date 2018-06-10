#ifndef RANGER_H
#define RANGER_H

#define _USE_MATH_DEFINES
#include <math.h>

#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <random>
#include <thread>
#include <mutex>
#include <condition_variable>

///Parent ranger class
class Ranger
{
public:
    Ranger();

    bool setBaud(double baud);
    bool setPort(int port);
    virtual bool setFeildView(int view);
    std::string getModel();
    double getBaud();
    std::string getPort();
    int getFeildView();
    double getMaxDist();
    double getMinDist();
    int getDataRate();
    void scanData(std::map<double,double> &data, std::chrono::_V2::system_clock::time_point &time, std::mutex &mtx, std::condition_variable &cv);
protected:
    int feildView_, dataRate_;
    double baud_, maxDist_, minDist_;
    std::string model_, port_;

    double omega_;
    double getNoise();
};

#endif // RANGER_H
