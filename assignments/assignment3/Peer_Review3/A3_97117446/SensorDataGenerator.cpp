#include <chrono>
#include <random>
#include "SensorDataGenerator.h"

// Constructor initialies the class object //////////////////////////////////////////////////////////////////////////
SensorDataGenerator::SensorDataGenerator()
{
    _mean = DEFAULT_MEAN;
    _stdDev = DEFAULT_STDDEV;
    _numOfValues = DEFAULT_NUMOFVALUES;
}

// RandomNormalDistribution (CLASS) Setters /////////////////////////////////////////////////////////////////////////

// sets the number of random numbers to be produced and sent back once getValues() is called //
void SensorDataGenerator::setNumOfValues(int number){
    _numOfValues = number;
}

// RandomNormalDistribution (CLASS) Getters /////////////////////////////////////////////////////////////////////////

// Sends the random numbers to the Ranger (BASE) class through passing by reference //
void SensorDataGenerator::getValues(std::vector<double>& randomNums){
    normalDistribution();
    for (int i=0; i<_numOfValues; i++){
        double y = _randomNums.back();
        _randomNums.pop_back();
        randomNums.push_back(y);
    }
}

// Sensor Data Generator Source file Function - Normal Distribution /////////////////////////////////////////////////

// Produces Sensor Data - this private method is called from getValues() //
void SensorDataGenerator::normalDistribution()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::normal_distribution<double> distribution(_mean,_stdDev);

    for (int i=0; i<_numOfValues; ++i) {
        double Num = distribution(generator);
        __int64_t time = std::chrono::duration_cast<std::chrono::microseconds>
                (std::chrono::system_clock::now().time_since_epoch()).count();

// this code is within the one line below //
//        double frequency = 0.05; //(f=0.05Hz)
//        double radPerSec = 2*M_PI*frequency;
//        double sinFunct = sin(radPerSec*time*pow(10,-6));
//        double sensorValue = (6+(4*sinFunct)+Num);
        double sensorValue = (6+(4*sin(2*M_PI*0.05*time*pow(10,-6)))+Num);

        _randomNums.push_back(sensorValue);
    }
}

