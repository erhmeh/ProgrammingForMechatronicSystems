#include "laser.h"
#include "ranger.h"
#include <iostream>
#include <random>
#include <chrono>

//Laser object constructor
Laser::Laser()
{
    double baudInput;
    int orientationInput;
    int angularResolutionInput;

    //upon construction, asks the user to set desired orientation offset
        std::cout<<"Please enter desired orientation offset:"<<std::endl;
        std::cin>>orientationInput;
        setOrientationOffset(orientationInput);

    //upon construction, asks the user to set desired baud rate
        std::cout<<"Please enter desired baud rate:"<<std::endl;
        std::cin>>baudInput;
        setBaud(baudInput);

        //upon construction, asks the user to set desired angular resolution
        std::cout<<"Please enter desired angular resolution:"<<std::endl;
            std::cin>>angularResolutionInput;
            setAngRes(angularResolutionInput);

    setPortNum();

    //fixed params
    model_ = "UTM-XXL";
    maxDistance_ = 8;
    minDistance_ = 0.2;
    fieldOfView_ = 180;
    numberOfSamples_ = 1;

    //initialises a map of <bearings, values@bearing> which is empty for now
    vector<double> values;
    for(int i=0; i<=fieldOfView_; i=i+10){
        data_.insert({i,values});
    }

}

//ensures angular resolution set is sane and valid, otherwise sets a default
bool Laser::setAngRes(int aR){
    if(aR == 10 || aR == 30){
            angularResolution_ = aR;
            return true;
        }
        else{
            angularResolution_ = 10;
            std::cout<<"Invalid value entered, angular resolution set to "<< angularResolution_<<std::endl;
            return false;
        }
}

//function randomly generates readings for each bearing
std::map<int, vector<double>> Laser::poll(){
cout<<"laser poll start"<<endl;

int mean = 6;
    int std_dev = 5;
    vector<double> tempVect;

   //random num gen setup
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator (seed);

        // Create a distribution with the provided parameters
        std::normal_distribution<double> distribution (mean, std_dev);

        // Push the specified number of values,
        // sampled from the distrubution
        for (int i = 0+orientationOffset_; i<=fieldOfView_+orientationOffset_; i=i+angularResolution_){ //change 10 to some sort of argument
            double j;
            tempVect=data_.at(i);

            //ensure randomly generated number is between min and max
            while(1){
                j=distribution(generator);
                if(j<=maxDistance_ && j>=minDistance_){
                    break;
                }
            }

            //amends the vector
            tempVect.push_back(j);
            //deletes the old pair
            data_.erase(i);
            //inserts pair with same key as deleted above but with amended vector
            data_.insert({i,tempVect});
            cout<<"degress: "<<i<< " reading: "<<tempVect.at(0)<<endl;
        }
        cout<<"laser poll complete"<<endl;
//        tempVect.~vector();
        return data_;
}
