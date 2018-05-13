#include "radar.h"
#include "ranger.h"
#include <iostream>
#include <random>
#include <chrono>

//Radar object constructor
Radar::Radar()
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


    setPortNum();

//fixed params
    model_ = "Rad-001";
    maxDistance_ = 16.0;
    minDistance_ = 0.2;
    fieldOfView_ = 60;
    numberOfSamples_ = 1;
    angularResolution_ = 20;

//    vector<double> values;                                   //60+70+10=140
//    for(int i=orientationOffset_-(angularResolution_/2); i<=fieldOfView_+orientationOffset_+(angularResolution_/2); i=i+(angularResolution_/2)){
//        data_.insert({i,values});

//    }


    //initialises a map of <bearings, values@bearing> which is empty for now
    vector<double> values;
    for(int i=0; i<=180; i=i+10){
        data_.insert({i,values});
    }
}

//function randomly generates readings for each bearing
std::map<int, vector<double>> Radar::poll(){
cout<<"ranger poll start"<<endl;
    int mean = 6;
    int std_dev = 5;
    vector<double> tempVect;
    double cone;
    //random num gen setup
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator (seed);

        // Create a distribution with the provided parameters
        std::normal_distribution<double> distribution (mean, std_dev);

        // Push the specified number of values,
        // sampled from the distrubution
        // loops through bearings to generate a reading for
        for (int i = 0+orientationOffset_; i<fieldOfView_+orientationOffset_; i=i+angularResolution_){
            //ensures randomly generated value is between min and max of the radar
            while(1){
                cone=distribution(generator);
                if(cone<=maxDistance_ && cone>=minDistance_){
                    break;
                }
            }

            // assign randomly generated val. to bearing -10*
            tempVect=data_.at((i-(angularResolution_/2)));
            tempVect.push_back(cone);
            data_.erase((i-(angularResolution_/2)));
            data_.insert({((i-(angularResolution_/2))), tempVect});

            // assign randomly generated val. to bearing
            tempVect=data_.at(i);
            tempVect.push_back(cone);
            data_.erase(i);
            data_.insert({(i), tempVect});

            // assign randomly generated val. to bearing +10*
            tempVect=data_.at((i+(angularResolution_/2)));
            tempVect.push_back(cone);
            data_.erase((i+(angularResolution_/2)));
            data_.insert({((i+(angularResolution_/2))), tempVect});

            cout<<"degress: "<<i<< "reading: "<<tempVect.at(0)<<endl;
        }
//        tempVect.~vector();
        cout<<"ranger poll end"<<endl;
        return data_;
}

