#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <math.h>
using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

#include "Laser.h"
#include "Radar.h"
#include "RangerFusion.h"


void queryFixedParameters(Ranger* ranger){
    cout << endl;
    cout << endl;
    cout << "*************************************************" << endl;
    cout << "Fixed Parameters of Ranger: Model: " << ranger->getModel() <<endl;
    cout << "\t" << "Field of View: " << ranger->getFieldOfView() << "  degrees" << endl;
    cout << "\t" << "Max Range: " << ranger->getMaxRange() << "  m" <<endl;
    cout << "\t" << "Min Range: " << ranger->getMinRange() << "  m" << endl;
    cout << endl;
    cout << "*************************************************" << endl;
    cout << endl;
}

void propmtUserParameterInput(Ranger* ranger){
    int portUserIn = 0;
    int baudUserIn = 0;
    int angularResUserIn = 0;
    double angularOffsetUserIn = 0.0;

    cout << "*************************************************" << endl;
    cout << "Configure Ranger: " << ranger->getModel() <<endl;
    cout << endl;
    cout << "*************************************************" << endl;

    cout << endl;
    cout << "Please select a Port (/dev/ttyACMX)" << endl;
    cout << "(choose from X = \"0\", \"1\", \"2\") "<< endl;
    cout << "X: ";
    cin >> portUserIn;

    bool portInputSane = ranger->setPort(portUserIn);
    if(portInputSane == true){
        cout << "Port set to: " << ranger->getPort() << endl;
        cout << endl;
    }
    if(portInputSane == false){
        cout << "Port set to default: " << ranger->getPort() << endl;
        cout << endl;
    }

    cout << "Please select the desired baud rate" << endl;
    cout << "(\"38400\", or \"115200\"): ";
    cin >> baudUserIn;

    bool baudInputSane = ranger->setBaudRate(baudUserIn);
    if(baudInputSane == true){
        cout << "Baud Rate set to: " << ranger->getBaudRate() << endl;
        cout << endl;
    }
    if(baudInputSane == false){
        cout << "Baud Rate set to default: " << ranger->getBaudRate() << endl;
        cout << endl;
    }

    cout << "Please select the Angular Resolution" << endl;
    cin >> angularResUserIn;

    bool angularResInputSane = ranger->setAngularRes(angularResUserIn);
    if(angularResInputSane == true){
        cout << "Angular Resolution set to: " << ranger->getAngularRes() << endl;
        cout << endl;
    }
    if(angularResInputSane == false){
        cout << "Angular Res set to default: " << ranger->getAngularRes() << endl;
        cout << endl;
    }

    cout << "Please select the Angular Offset" << endl;
    cout << endl;
    cout << "NOTE: the ranger that will be used as the reference resolution " << endl;
    cout << "for the fusion should have an offset of 0 degrees" << endl;
    cin >> angularOffsetUserIn;

    bool angularOffsetInputSane = ranger->setAngularOffset(angularOffsetUserIn);
    if(angularOffsetInputSane == true){
        cout << "Angular Offset set to: " << ranger->getAngularOffset() << endl;
        cout << endl;
    }
    if(angularOffsetInputSane == false){
        cout << "Angular Offset set to default: " << ranger->getAngularOffset() << endl;
        cout << endl;
    }

}


void printRangerParameters(Ranger* ranger){
    cout << "******************************************************" << endl;
    cout << "Ranger: \t" << ranger->getModel() << endl;
    cout << "******************************************************" << endl;
    cout << "Baud: \t\t" << ranger->getBaudRate() << endl;
    cout << "Port: \t\t" << ranger->getPort() << endl;
    cout << "Field of View: \t" << ranger->getFieldOfView() << endl;
    cout << "Angular Resolution: \t" << ranger->getAngularRes() << endl;
    cout << "Max Distance: \t\t" << ranger->getMaxRange() << " m" << endl;
    cout << "Min Distance: \t\t" << ranger->getMinRange() << " m" << endl;
    cout << endl;
    cout << "Orientation: " << endl;
    cout << "\t\t Angular Offset: " << ranger->getAngularOffset() << endl;
    cout << "******************************************************" << endl << endl;

}

void printRawData(vector<vector<double> > rawData, vector<Ranger*> rangers){

    for(int i = 0; i < rawData.size(); i++){
        vector<double> dataSet = rawData.at(i);
        cout << "Raw Data for: " << rangers.at(i)->getModel() << endl;
        cout << "\t{ ";
        for(auto sample : dataSet){
            cout << sample << ", ";
        }
        cout << "}" << endl;

    }
}



int main(){


// 1) Initialise the sensors (1 Laser, 2 Radar) //////////////////////////////////////////

// ///Configuration 1 ///////////////////
//    Laser laser1(0, 38400, 30, 0.0);
//    Radar radar1(1, 38400, 20, 70.0);
//    Radar radar2(2, 38400, 20, 70.0);


// ///Configuration 2 ///////////////////
    Laser laser1(0, 38400, 10, 0.0);
    Radar radar1(1, 38400, 20, 40.0);
    Radar radar2(2, 38400, 20, 100.0);

    vector<Ranger*> rangers = {&radar1, &radar2, &laser1};


// 2) Query the fixed parameters /////////////////////////////////////////////////////////

    for (auto ranger: rangers){
        queryFixedParameters(ranger);
    }



// 3) Sets sensor parameters as specified by the user ////////////////////////////////////

    for (auto ranger: rangers){
        propmtUserParameterInput(ranger);
    }
    for (auto ranger: rangers){
        printRangerParameters(ranger);
    }



// 4) Continuously calls (each second) the RangerFusion class and obtains the fused data output
    RangerFusion rangerFuser("average");
    rangerFuser.setRangers(rangers);

    string fusionMethodUserIn;
    cout << "Please select the Fusion Method" << endl;
    cout << "(\"min\", or \"max\", or \"average\"): ";
    cin >> fusionMethodUserIn;


    bool fusionMethodInputSane = rangerFuser.setFusionMethod(fusionMethodUserIn);
    if(fusionMethodInputSane == true){
        cout << "Fusion Method set to: " << rangerFuser.getFusionMethod() << endl;
        cout << endl;
    }
    if(fusionMethodInputSane == false){
        cout << "Fusion Method set to default: " << rangerFuser.getFusionMethod() << endl;
        cout << endl;
    }



    cout << endl;
    cout << "*************************************************" << endl;
    cout << endl;

    while (true){
        // Obtain raw data from RangerFuser
        vector<vector<double > > rawData = rangerFuser.getRawRangeData();

        printRawData(rawData, rangers);

        // Get the fused data from rangerFuser
        vector<double> fusedData = rangerFuser.getFusedRangeData();

        cout << "Fused data: {";
        for(double value:fusedData){
            cout << value << ", ";
        }
        cout << "}" << endl;
        cout << endl;
        cout << "*************************************************" << endl;
        cout << endl;


        // This delay will set the output rate to to once every second.
        int delay = pow(10.0,9.0);
        sleep_for(nanoseconds(delay));
     }


    return 0;
}
