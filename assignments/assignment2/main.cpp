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
#define LASER_ANGULAR_RES 30

Laser laser;
Radar1 radar1;
Radar2 radar2;

void initLaser();
void initRadar1();
void initRadar2();

void initLaser(){
        cout << "Fixed Params:" << endl;
        cout << "Model Number: UTM-XXL" << endl;
        cout << "FOV: " << laser.getFov() << endl;
        cout << "Min distance: " << laser.getMinDistance() << endl;
        cout << "Max distance: " << laser.getMaxDistance() << endl;
        cout << "Configuring user defined variables:" << endl;
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
        if (laser.setAngularRes(LASER_ANGULAR_RES)) {
                cout << "Angular Resolution set: " << laser.getAngularRes() << endl;
        }
        else{
                cout << "Invalid Angular Resolution. Default value used: " << laser.getAngularRes() << endl;
        }
}

int main(){
        initLaser();
        return 0;
}
