#include "ranger.h"
#include <iostream>
int port=0;
//int MEAN = 6;
//int STD_DEV = 5;
Ranger::Ranger()
{
//    orientationOffset_ = 1;
//    fieldOfView_ = 1;
//    numberOfSamples_ = 1;
//    portNum_ = 1;
//    model_ = "one";
//    baud_ = 1;
//    maxDistance_ = 1;
//    minDistance_ = 1;
}

//common functions between radar and laser
bool Ranger::setBaud(double b){
    if(b == 38400 || b == 115200){
            baud_ = b;
            return true;
        }
        else{
            baud_ = 38400;
            std::cout<<"Invalid value entered, baud set to "<< baud_<<std::endl;
            return false;
        }
}

bool Ranger::setOrientationOffset(int oO){
    if(oO >= 0 && oO <= 180){
            orientationOffset_ = oO;
            return true;
        }
        else{
            orientationOffset_ = 0;
            std::cout<<"Invalid value entered, orientation offset set to "<< orientationOffset_<<std::endl;
            return false;
        }
}

//sets portnum of ranger objects based on order of creation
void Ranger::setPortNum(){
    portNum_ = port;
    port++;
}

//common print params function
void Ranger::printParams(){
    std::cout<< "Orientation offset = " <<orientationOffset_<<std::endl;
    std::cout<< "Field of View = " <<fieldOfView_<<std::endl;
//    std::cout<< "Number of Samples = " <<numberOfSamples_<<std::endl;
    std::cout<< "Port Number = " <<portNum_<<std::endl;
    std::cout<< "Model = " <<model_<<std::endl;
    std::cout<< "Baud Rate = " <<baud_<<std::endl;
    std::cout<< "Max Distance = " <<maxDistance_<<std::endl;
    std::cout<< "Min Distance = " <<minDistance_<<std::endl;
    std::cout<< "Angular Resolution = " <<angularResolution_<<std::endl;


}

//unused or not common functions
map<int,vector<double>> Ranger::poll(void){}

std::string Ranger::getModel(){}

double Ranger::getBaud(){}

int Ranger::getPort(){}

int Ranger::getFOV(){}

int Ranger::getAngRes(){}

//prints warning that a base version of function is being used instead of derived versions
bool setAngRes(int){
    std::cout<<"accessing ranger.cpp setAngRes BAD BAD BAD"<<std::endl;
    return true;
}

double Ranger::getMaxDist(){}

double Ranger::getminDist(){}
