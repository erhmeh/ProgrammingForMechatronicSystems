#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <random>           //enable random generator
#include <math.h>           //enable math functionality throughout code
#include <unistd.h>         //for usleep

class Sensor{               //class establishing sensor functionality and definitions
private:
    int defBaudRate;
    int defPort;
    double defAngRes;
    int defScanTime;
    double minDist;
    double maxDist;
public:
    Sensor(void);                       //constructor with default values
    //setters
    bool setBaudRate(int BaudRate);
    bool setPort(int port);
    bool setAngRes(double AngRes);
    bool setScanTime(int ScanTime);

    //getters
    int getBaudRate(void);
    int getPort(void);
    double getAngRes(void);
    int getScanTime(void);
    double getSensorData(int);

    void scanning(void);                //function for sensor scanning, reading and printing

};
#endif // SENSOR_H
