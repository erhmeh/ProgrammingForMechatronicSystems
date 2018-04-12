#include <iostream>
#include <vector>
#include "Ranger.h"
#include "Radar1.h"
#include "Radar2.h"
#include "Laser.h"

using namespace std;

#define LASER_BAUD 38400.0
#define LASER_XOFFSET 0.0

#define LASER_BAUD_DEFAULT 38400.0
#define LASER_XOFFSET_DEFAULT 0.0

Laser laser;
Radar1 radar1;
Radar2 radar2;

void initLaser();
void initRadar1();
void initRadar2();

void initLaser(){
        if (laser.setBaudRate(LASER_BAUD)) {
                cout << "Baud Rate set." << endl;
        }
        else{
                laser.setBaudRate(LASER_BAUD_DEFAULT);
                cout << "Invalid baud rate. Default value used." << endl;
        }
        if (laser.setXOffset(LASER_XOFFSET)) {
                cout << "X offset set." << endl;
        }
        else{
                laser.setBaudRate(LASER_XOFFSET_DEFAULT);
                cout << "Invalid offset. Default value used." << endl;
        }
}

int main(){

        return 0;
}
