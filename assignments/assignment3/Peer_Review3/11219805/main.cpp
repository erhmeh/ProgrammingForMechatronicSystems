#include "ranger.h"
#include "sonar.h"
#include "radar.h"
#include "rangerfusion.h"
#include "rangerfusioninterface.h"

#include <iostream>
#include <limits>
#include <vector>
#include <chrono>
#include <string.h>
#include <mutex>
#include <condition_variable>

using namespace std;

///Print a blank line to help organise user interface
void printBreak(){
    cout<<endl;
}

///Clears input stream
void flush(istream& in){
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    in.clear();
}

///Waits for user to press enter
void pause(){
    cout<<"Press ENTER to begin scanning";
    cin.get();
}

///Print that an input was invalid
void invalidValue(){
    cout<<"Invalid value, using default setting"<<endl;
}

///Call and print the fixed parameters of the sensor
void parameterCheck(Ranger& sensor)
{
    cout<<"Model: "<<sensor.getModel()<<endl;
    cout<<"Baud: "<<sensor.getBaud()<<endl;
    cout<<"Port: "<<sensor.getPort()<<endl;
    cout<<"Field of View: "<<sensor.getFeildView()<<" degrees"<<endl;
    cout<<"Max Distance: "<<sensor.getMaxDist()<<" m"<<endl;
    cout<<"Min Distance: "<<sensor.getMinDist()<<" m"<<endl;
    cout<<"Data Rate: "<<sensor.getDataRate()<<" Hz"<<endl;
}

///Set configurable sensor parameters from user input
void parameterSet(Ranger& sensor)
{
    double input;

    cout<<"Choose Baud (38400/115200): ";
    cin>>input;
    if(!sensor.setBaud(input)){
        invalidValue();
    }
    cout<<"Choose Port (0/1/2): ";
    cin>>input;
    if(!sensor.setPort(input)){
        invalidValue();
    }
    ///Checks whether sensor is a radar
    if (sensor.getModel().compare("RAD-001")==0){
        cout<<"Choose Field of View (20/40): ";
        cin>>input;
        if(!sensor.setFeildView(input)){
            invalidValue();
        }
    }
}
///Loops through data generation function, used by sensor threads
void generateData(Ranger& sensor, map<double,double>& data, chrono::system_clock::time_point& time, mutex& mtx, condition_variable& cv){
    while(1){
        sensor.scanData(data, time, mtx, cv);
    }
}
///Loops through data fusion function, used by fusion thread
void printFusedData(RangerFusion& rangerFusion, vector<map<double,double>>& data, chrono::system_clock::time_point& time, mutex& mtx, condition_variable& cv){
    while(1){
        double fusedData = rangerFusion.getFusedRangeData(data, time, mtx, cv);
        cout<<"Fused Sensor Data: "<<fusedData<<endl;
        printBreak();
    }
}

/*Main code*/
int main(){
    ///Initialises local variables and containers
    char yesNo;
    string fuseType;
    int loopNum;
    vector<map<double,double>> data;
    vector<Ranger*> sensors;
    mutex mtx;
    condition_variable cv;

    /*Setup Code*/
    cout<<"Initialising Sensors"<<endl;
    ///Creates a sonar and radar object of the ranger class
    Radar sensor1;
    sensors.push_back(&sensor1);
    Sonar sensor2;
    sensors.push_back(&sensor2);
    data.resize(sensors.size());
    printBreak();
    ///Queries user to check sensor parameters
    cout<<"Do you want to check sensor parameters? (Y/N): ";
    cin>>yesNo;
    printBreak();
    if (yesNo == 'Y'||yesNo == 'y')
    {
        loopNum = 1;
        for (auto& sensNum : sensors){
            cout<<"Checking parameters for senor "<<loopNum<<endl;
            loopNum++;
            parameterCheck(*sensNum);
            printBreak();
        }
    }
    printBreak();
    ///Queries user to set sensor parameters
    cout<<"Do you want to set configurable parameters? (Y/N): ";
    cin>>yesNo;
    printBreak();
    if (yesNo == 'Y'||yesNo == 'y')
    {
        loopNum = 1;
        for (auto& sensNum : sensors){
            cout<<"Setting configurable parameters for senor: "<<loopNum<<endl;
            loopNum++;
            parameterSet(*sensNum);
            printBreak();
        }
    }
    printBreak();
    ///Queries user for sensor fusion method
    cout<<"Choose data fusion method (Min, Max, Avg): ";
    cin>>fuseType;
    ///Creates an object of the ranger fusion class
    RangerFusion rangerFusion(fuseType);
    printBreak();
    ///Pauses code until user input
    flush(cin);
    pause();
    ///Initialises clock
    auto start = chrono::high_resolution_clock::now();

    /*Creates threads to continuosly run create and fuse data*/
    thread sensor1_thread(generateData, ref(sensor1), ref(data[0]), ref(start), ref(mtx), ref(cv));
    thread sensor2_thread(generateData, ref(sensor2), ref(data[1]), ref(start), ref(mtx), ref(cv));
    thread fusion(printFusedData, ref(rangerFusion), ref(data), ref(start), ref(mtx), ref(cv));

    sensor1_thread.join();
    sensor2_thread.join();
    fusion.join();

    return 0;
}
