#include <iostream>
#include <vector>
#include "Ranger.h"
#include "Radar1.h"
#include "Radar2.h"
#include "Laser.h"

using namespace std;

#define LASER_BAUD 38400
#define LASER_XOFFSET 0
#define LASER_OOFFSET 0
#define LASER_TTY 2

Laser laser;
Radar1 radar1;
Radar2 radar2;

void startSensors();
void initLaser();
void initRadar1();
void initRadar2();

void startSensors(){
        initLaser();
        initRadar1();
        initRadar2();
}

void initLaser(){
        Laser();
        if (laser.setBaudRate(LASER_BAUD)) {
                cout << "Baud Rate set: " << laser.getBaudRate() << endl;
        }
        else{
                cout << "Invalid baud rate. Default value used: " << laser.getBaudRate() << endl;
        }
        if (laser.setXOffset(LASER_XOFFSET)) {
                cout << "X offset set: " << laser.getXOffset() << endl;
        }
        else{
                cout << "Invalid offset. Default value used: " << laser.getXOffset() << endl;
        }
        if (laser.setOOffset(LASER_OOFFSET)) {
                cout << "Orientation offset set: " << laser.getOOffset() << endl;
        }
        else{
                cout << "Invalid orientation offset. Default value used: " << laser.getOOffset() << endl;
        }
        if (radar1.getTty() != LASER_TTY && radar2.getTty() != LASER_TTY && laser.setTtyACM(LASER_TTY)) {
                cout << "Laser has been attached as ttyACM" << LASER_TTY << endl;
        }
        else{
                if(radar1.getTty() == 0 || radar2.getTty() == 0) {
                        if (radar1.getTty() == 1 || radar2.getTty() == 1) {
                                laser.setTtyACM(2);
                                cout << "Laser has been attached to ttyACM2" << endl;
                        }
                        else{
                                laser.setTtyACM(1);
                                cout << "Laser has been attached to ttyACM1" << endl;
                        }
                }
                else{
                        laser.setTtyACM(0);
                        cout << "Laser has been attached to ttyACM0" << endl;
                }
        }
}

int main(){
        startSensors();
        return 0;
}
