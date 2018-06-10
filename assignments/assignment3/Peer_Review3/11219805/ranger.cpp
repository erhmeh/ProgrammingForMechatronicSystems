#include "ranger.h"

///Constructor defaults generic configurable parameters
Ranger::Ranger(): baud_(38400), port_("/dev/ttyACM0"),omega_(2*M_PI*0.05){
}
///Funtion to set Baud from valid input
bool Ranger::setBaud(double baud){
    if (baud == 38400 || baud == 115200) {
        baud_ = baud;
        return 1;
    }
    ///Default Baud when input is invalid
    else{
        baud_ = 38400;
        return 0;
    }
}
///Function to set Port from valid input
bool Ranger::setPort(int port){
    if (port >= 0 && port <=2){
        port_ = "/dev/ttyACM" + std::to_string(port);
        return 1;
    }
    ///Default Port when input invalid
    else{
        port_ = "/dev/ttyACM" + std::to_string(0);
        return 0;
    }
}
///Virtual function to set feild of view, used by radar class
bool Ranger::setFeildView(int view){
}
///Returns the Sensor Model
std::string Ranger::getModel(){
    return model_;
}
///Returns the configured Baud
double Ranger::getBaud(){
    return baud_;
}
///Returns the selected Port
std::string Ranger::getPort(){
    return port_;
}
///Returns the Feild of View of the sensor
int Ranger::getFeildView(){
    return feildView_;
}
///Returns the Maximum Distance the sensor can detect
double Ranger::getMaxDist(){
    return maxDist_;
}
///Returns the Minimum Distance the sensor can detect
double Ranger::getMinDist(){
    return minDist_;
}
///Returns the rate at which the sensor detects data
int Ranger::getDataRate(){
    return dataRate_;
}
/*Populates a map with sensor scan data
It compares current time to initial time point from input
then creates data and inputs it to a map with key of time*/
void Ranger::scanData(std::map<double,double> &data, std::chrono::high_resolution_clock::time_point &time, std::mutex &mtx, std::condition_variable &cv){
    std::unique_lock<std::mutex> lck(mtx);
    auto current = std::chrono::high_resolution_clock::now();
    auto currentTime = std::chrono::duration_cast<std::chrono::seconds>(current-time);
    data[currentTime.count()] = 6+(4*sin(omega_*currentTime.count())+getNoise());
    lck.unlock();
    cv.notify_all();

    int delay = 1000/dataRate_;
    std::this_thread::sleep_for (std::chrono::milliseconds(delay));
}
///Simulate sensor noise with Gaussian Distribution
double Ranger::getNoise(){
    std::default_random_engine generator;
    std::normal_distribution<double> noiseRange(0,0.1);
    double noise = noiseRange(generator);
    return noise;
}
