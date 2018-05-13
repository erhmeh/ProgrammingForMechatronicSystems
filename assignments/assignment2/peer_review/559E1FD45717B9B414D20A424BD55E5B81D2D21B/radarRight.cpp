#include "radarRight.h"
#include <iostream>

RadarRight::Radar() {
    model = "RAD-001";
    port = PORT_0;
    FOV = RADARFOV_1;
    minDistance = MINDISTANCE;
    maxDistance = MAXDISTANCE;
    samples = 0;
}

//boolean conditions

bool RadarRight::setFOV(int FOfV) {
    if (FOfV == RADARFOV_1 || FOfV == RADARFOV_2) {
        FOV = FOfV;
        return true;
    } else {
        cin.clear(); //ensure to use default values if char input instead of integer, applied to other setters
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input is invalid - defaulting to: " << RADARFOV_1 << endl;
    }
}

void RadarRight::radarRightReading() {
    int boundary_1 = (150 - (FOV / 2));
    int boundary_2 = (150 + (FOV / 2));
    int currentAngle = 0;
    double value;
    for (int i = 0; i < ARRAYSIZE; i++) {
        if ((currentAngle >= boundary_1) && (currentAngle <= boundary_2)) {
            value = distGenerator();
            if ((value > minDistance) && (value < maxDistance)) {
                data[i] = value;
            } else {
                data[i] = -1.0;
            }
            samples++;
        } else {
            data[i] = -1.0;
        }
        currentAngle += 15;
    }
}

double* RadarRight::getData() {
    radarRightReading();
    return data;
}
