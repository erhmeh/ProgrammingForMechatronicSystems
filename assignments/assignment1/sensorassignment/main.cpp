#include <iostream>
#include <time.h>
#include <thread>
#include <chrono>
#include "accelerometer.h"

using namespace std;

int main()
{
    Accelerometer sensor;

    while(sensor.setBaud(19200) && sensor.setMaxAcceleration(50) && sensor.setUSB(0)){
    sensor.takeSample();
    sensor.convSample();
    cout << "X = " <<sensor.getX() << endl;
    cout << "Y = " <<sensor.getY() << endl;
    cout << "Z = " <<sensor.getZ() << endl;
    cout << "" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    cout << "Invalid sensor settings" << endl;
    return 0;
}
