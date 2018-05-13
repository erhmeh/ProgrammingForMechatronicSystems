#ifndef RANGER_H
#define RANGER_H

//USING DEFINITIONS INSTEAD OF "MAGIC NUMBERS"
#define BAUDRATE_1 38400
#define BAUDRATE_2 115200
#define PORT_0 0
#define PORT_1 1
#define PORT_2 2
#define MAXRADAR 16.00
#define MINRADAR 0.20
#define MEAN 6
#define STD 5
#define ARRAYSIZE 15

#include <chrono>
#include <random>


using namespace std;

template <class RealType = double> class normal_distribution;
//http://www.cplusplus.com/reference/random/normal_distribution/

class Ranger {
protected:
    char* model; //ranger model
    int baudRate; //baud rate of ranger
    int port; //the port which ranger is connected to
    double FOV; //field of view of ranger
    double maxDistance; //max detect distance of ranger
    double minDistance; //min detect distance of ranger

    double data[ARRAYSIZE]; //data array where ranger data is stored, max number of readings is ARRAYSIZE = 15
    int samples; //number of samples the ranger has taken

    double distGenerator();


public:
    Ranger(); //constructor for Ranger base class

    //setters
    bool setBaudRate(int baudInput);
    bool setPort(int portInput);

    //getters
    int getBaudRate();  //returns the ranger baudrate
    int getPort();      //returns port that ranger is connected to
    int getFOV();       //returns ranger fov
    double getSensorData();
    int getSamples();   //returns stored data in array of ranger
    char* getModel();   //char* is a pointer to a character
    virtual double* getData(); //returns the port that the ranger is connected to
    double getMaxDist();
    double getMinDist();
};

#endif /* RANGER_H */
