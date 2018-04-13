#include "sensor.h"

using namespace std;

int dataCount;

Sensor::Sensor()                                //default parameters set up in constructor for sensor
{
    defBaudRate = 38400;
    defPort = 0;
    defAngRes = 1.0;
    defScanTime = 25;
    minDist = 0.2;
    maxDist = 8.0;
}

//setters using boolean conditions
bool Sensor::setBaudRate(int BaudInput)         //boolean test for baud rate setter
{
    if(BaudInput == 38400 || BaudInput == 115200){
        defBaudRate = BaudInput;
        return true;
    }
    else{
        cin.clear();                            //ensure to use default values if char input instead of integer, applied to other setters
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input is invalid - default value set: " << defBaudRate << endl;
    }
}

bool Sensor::setPort(int PortInput)             //boolean test for port setup setter
{
    if(PortInput == 0 || PortInput == 1 || PortInput == 2){
        defPort = PortInput;
        return true;
    }
    else{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input is invalid - default value set: " << defPort << endl;
    }
}

bool Sensor::setAngRes(double AngResInput)      //boolean test for angle resolution setter
{
    if(AngResInput == 0.5 || AngResInput == 1.0){
        defAngRes = AngResInput;
        return true;
    }
    else{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input is invalid - default value set: " << defAngRes << " deg" << endl;
    }
}

bool Sensor::setScanTime(int ScanTimeInput)
{
    if(ScanTimeInput == 25 || ScanTimeInput == 50){
        defScanTime = ScanTimeInput;
        return true;
    }
    else{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input is invalid - default value set: " << defScanTime << " ms" << endl;
    }
}

//getters
int Sensor::getBaudRate()       //baud rate getter to retrieve the default baud rate
{
    return(defBaudRate);
}

int Sensor::getPort()           //port getter to retrieve the default port
{
    return(defPort);
}

double Sensor::getAngRes()      //angle resolution getter to retrieve the default angle resolution
{
    return(defAngRes);
}

int Sensor::getScanTime()       //scan time getter to retrive the default scan time
{
    return(defScanTime);
}

//scanning, reading & printing sensor data with random generator
void Sensor::scanning()
{
    cout << "Scan Initiated." << endl;
    random_device random;                                                   //established to hold value from generator
    default_random_engine generator(random());                              //random generator giving "random" data
    uniform_real_distribution<double> distribution(minDist,maxDist);        //establishes the minimum and maximum thresholds for the random values

    while(1){                                                               //while loop to continuously print data
        for(double x = 0; x < 181; x += defAngRes){
            cout << "Sensor angle: " << x << "   Distance (m): " << distribution(random) << endl;       //print the random values generated
            usleep(defScanTime*1000);                                       //takes the inputted scanning time
        }
    }
}





















