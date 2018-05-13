#include "laser.h"
#include <iostream>
using namespace std;

Laser::Laser() {
    FOV = LASERFOV;
    baudRate = BAUDRATE_1;
    port = PORT_0;
    maxDistance = MAXLASER;
    minDistance = MINLASER;
    angleRes = ANGLERES_1;
    samples = 0;
}

//setting boolean conditions

bool Laser::setAngleRes(int resolutionInput) {
    if (resolutionInput == ANGLERES_1 || resolutionInput == ANGLERES_2) {
        angleRes = resolutionInput;
        return true;
    } else {
        cin.clear(); //ensure to use default values if char input instead of integer, applied to other setters
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input is invalid - defaulting to: " << ANGLERES_1 << endl;
    }
}

void Laser::laserScan() {
    int boundary_1 = (90 - (FOV / 2));
    int boundary_2 = (90 + (FOV / 2));
    int currentAng = 0;
    int o = 1;
    if (angleRes == ANGLERES_2) {
        o = 2;
    }
    double value;
    for (int i = 0; i < ARRAYSIZE; i += o) {
        if ((currentAng >= boundary_1) && (currentAng <= boundary_2)) {
            value = distGenerator();
            if ((value > minDistance) && (value < maxDistance)) {
                data[i] = value;
            } else {
                data[i] = -1.0;
            }
            currentAng + - angleRes;
        }
    }
}

double* Laser::getData() {
    laserScan();
    return data;
}