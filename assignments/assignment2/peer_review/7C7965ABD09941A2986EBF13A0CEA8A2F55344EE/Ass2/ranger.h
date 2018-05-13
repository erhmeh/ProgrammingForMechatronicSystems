#ifndef RANGER_H
#define RANGER_H
#include <string>
#include <map>
#include <vector>

using namespace std;

class Ranger
{
public:
    Ranger();
    Ranger(int orientationOffset, int fieldOfView, int angularResolution, int numberOfSamples, double data, int usbPort );
    bool setOrientationOffset(int);
    bool setBaud(double);
    void setPortNum();
    bool setAngRes(int); //make virtual?
    void printParams();
    virtual std::map<int, vector<double>> poll(void);
    std::string getModel();
    double getBaud();
    int getPort();
    int getFOV();
    int getAngRes();
    double getMaxDist();
    double getminDist();
protected:
    int angularResolution_;
    int orientationOffset_;
    int fieldOfView_;
    int numberOfSamples_;
    map<int, vector<double>> data_;
    int portNum_;
    std::string model_;
    double baud_;
    double maxDistance_;
    double minDistance_;
private:


};

#endif // RANGER_H
