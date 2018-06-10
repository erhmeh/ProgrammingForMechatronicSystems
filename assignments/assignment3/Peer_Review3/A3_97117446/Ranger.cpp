#include <string>
#include <iostream>

#include "Ranger.h"

// Constructor initialies the class object //////////////////////////////////////////////////////////////////////////
Ranger::Ranger(){
    _timeStarted = false;
    _bufferDelay = 50;
}

// Ranger Source file Function - Valid //////////////////////////////////////////////////////////////////////////////

// Checks to determine if the input, of data type double, is valid //
bool Ranger::valid(std::vector<int> option, int input){
    bool valid = false;
    for(int i = 0 ; i < option.size() ; i++){
        if (input == option[i]){
            valid = true;
        }
    }
    return valid;
}

// Ranger Source file Function - Valid //////////////////////////////////////////////////////////////////////////////

// Checks to determine if the input, of data type double, is valid //
bool Ranger::valid(std::vector<double> option, double input){
    bool valid = false;
    for(int i = 0 ; i < option.size() ; i++){
        if (input == option[i]){
            valid = true;
        }
    }
    return valid;
}

// Ranger(BASE CLASS) Setters ///////////////////////////////////////////////////////////////////////////////////////

void Ranger::setBaud(int baud){
    if (valid(_baudOptions, baud) == true){
        _baud = baud;
    }else{
        _baud = _defaultBaud;
    }
}
void Ranger::setPort(int port){
    if (valid(_portOptions, port) == true){
        _port = port;
    }else{
        _baud = _defaultPort;
    }
}
void Ranger::setFieldOfView(double fieldOfView){
    if (valid(_fieldOfViewOptions, fieldOfView) == true){
        _fieldOfView = fieldOfView;
    }else{
        _fieldOfView = _defaultFieldOfView;
    }
}
void Ranger::setAngularResolution(double angularResolution){
    if (valid(_angularResolutionOptions, angularResolution) == true){
        _angularResolution = angularResolution;
    }else{
        _angularResolution = _defaultAngluarResolution;
    }
}
void Ranger::setSensorName(std::string sensorName){
    _sensorName = sensorName;
}

// Ranger(BASE CLASS) Getters ///////////////////////////////////////////////////////////////////////////////////////

std::string Ranger::getModel(){
    return _model;
}
int Ranger::getBaud(){
    return _baud;
}
int Ranger::getPort(){
    return _port;
}
int Ranger::getFieldOfView(){
    return _fieldOfView;
}
int Ranger::getAngularResolution(){
    return _angularResolution;
}
double Ranger::getMaxDistance(){
    return _maxDistance;
}
double Ranger::getMinDistance(){
    return _minDistance;
}
double Ranger::getDataRate(){
    return _dataRate;
}
std::string Ranger::getSensorName(){
    return _sensorName;
}

void Ranger::getParameterOptions(std::string parameter, std::vector<double>& options){
    if (parameter == "Baud"){
        options = _baudOptions;
    }else if(parameter == "Port"){
        options = _portOptions;
    }else if (parameter == "Field Of View"){
        options = _fieldOfViewOptions;
    }
}

double Ranger::getOrientationOffset(){
    return _orientationOffset;
}

double Ranger::getMaxOrientationOffset(){
    return _maxOrientationOffset;
}

double Ranger::getMinOrientationOffset(){
    return _minOrientationOffset;
}

int Ranger::getBufferDelay(){
    return _bufferDelay;
}

double Ranger::getStartTime(){
    return _startTime;
}

// Ranger Source file Function - Data Generator /////////////////////////////////////////////////////////////////////

// This class member sets the number of samples and then requests //
void Ranger::DataGenerator(){
    if (_timeStarted == false){
        _startTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        _timeStarted = true;
    }

    _numberOfSamples = _fieldOfView/_angularResolution;
    _data.clear();
    std::vector <double> sample;

    // if the sample is out of the senors range then the sample is rejected and a new sample is produced.
    SensorData.setNumOfValues(_numberOfSamples); // tells RandomNormalDistribition class how many samples it would like to receive
    sample.clear();
    SensorData.getValues(sample); // receives the generated random numbers from RandomNormalDistribition class
    for (int i = 0 ; i < sample.size() ; i++){
        if (sample[i] <= _minDistance){
            _data.push_back(_minDistance);
        }
        else if (sample[i] >= _maxDistance){
            _data.push_back(_maxDistance);
        }
        else{
            _data.push_back(sample[i]);
        }
    }
    int delayMS = (1/_dataRate)*1000;
    std::this_thread::sleep_for (std::chrono::milliseconds(delayMS-_bufferDelay));
}

// Ranger Source file Function - Sensor Thread //////////////////////////////////////////////////////////////////////

void Ranger::sensorThread(std::deque<std::deque<double> >& sensorData){
    //_counter = 0;
    double maxFlag;
    while (true){
        _sensorMutex.lock();
        DataGenerator();
        for (int i = 0 ; i < _data.size() ; i++){
            sensorData[rangerDeque].push_back(_data[i]);
            sensorData[timeDeque].push_back((std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count()) - getStartTime());
            maxFlag = 0;
            if (_data[i] >= getMaxDistance()){
                maxFlag = 1;
            }
            sensorData[maxDeque].push_back(maxFlag);
        }
        _sensorcondvar.notify_all();
        _sensorMutex.unlock();
        std::this_thread::sleep_for (std::chrono::milliseconds(getBufferDelay()));
    }
}

// Ranger Source file Function - Buffer Function ////////////////////////////////////////////////////////////////////

//generates the buffer for the Ranger Fusion to use //
void Ranger::bufferFunct(std::deque<std::deque<double> >& consumerBuffer
                         ,std::deque<std::deque<double> >& producerBuffer
                         ,bool bufferFlag){
    const int bufferSize = 2;
    for (int i = 0 ; i < producerBuffer[rangerDeque].size() ; i++){
        consumerBuffer[rangerDeque].push_back(producerBuffer[rangerDeque][i]);
        consumerBuffer[timeDeque].push_back(producerBuffer[timeDeque][i]);
        consumerBuffer[maxDeque].push_back(producerBuffer[maxDeque][i]);
    }
    if (bufferFlag == false){
        producerBuffer[rangerDeque].clear();
        producerBuffer[timeDeque].clear();
        producerBuffer[maxDeque].clear();
    }else if(bufferFlag == true){
        while (consumerBuffer[rangerDeque].size() > bufferSize
               || consumerBuffer[timeDeque].size() > bufferSize
               || consumerBuffer[maxDeque].size() > bufferSize){
            consumerBuffer[rangerDeque].pop_front();
            consumerBuffer[timeDeque].pop_front();
            consumerBuffer[maxDeque].pop_front();
        }
    }
}

// Ranger Source file Function - Buffer Function ////////////////////////////////////////////////////////////////////

// another version without specifying the if it is generating a buffer output or a new values output
//, thus default to no being a buffer output
void Ranger::bufferFunct(std::deque<std::deque<double> > &consumerBuffer
                         ,std::deque<std::deque<double> > &producerBuffer){
    bool bufferFlag = false;
    bufferFunct(consumerBuffer, producerBuffer, bufferFlag);
}

// Ranger Source file Function - Buffer Thread //////////////////////////////////////////////////////////////////////

// gains data from the sensors and then sends this data to to the fusion method.
void Ranger::bufferThread(std::mutex& Mutex, std::condition_variable& condvar
                          ,std::deque<std::deque<double> >& sensorData
                          ,std::deque<std::deque<double> >& rawData
                          ,std::deque<std::deque<double> >& buffer){
    while (true){
        std::deque<std::deque<double> > bufferThreadDataBuffer = {{}, {}, {}};

        std::unique_lock<std::mutex> sensorlocker(_sensorMutex);
        _sensorcondvar.wait(sensorlocker);
        bufferFunct(bufferThreadDataBuffer, sensorData);
        _sensorcondvar.notify_all();
        _sensorMutex.unlock();

        std::unique_lock<std::mutex> rangerlocker(Mutex);
        bool bufferFlag = true;
        bufferFunct(buffer, bufferThreadDataBuffer, bufferFlag);
        bufferFunct(rawData, bufferThreadDataBuffer);
        condvar.notify_all();
        Mutex.unlock();
    }
}

// Ranger Source file Function - Buffer Function ////////////////////////////////////////////////////////////////////

// virtual destructor to make the Derived class abstract //
//, to ensure nobody tries and instantiate an object of type Ranger //

Ranger::~Ranger() {}
