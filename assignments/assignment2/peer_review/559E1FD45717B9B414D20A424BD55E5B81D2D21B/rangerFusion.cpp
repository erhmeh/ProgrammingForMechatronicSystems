#include "rangerFusion.h"


void RangerFusion::getRangers(Ranger *rangers[]) {
    laserSensor = rangers[0];
    radarLeft = rangers[1];
    radarRight = rangers[2];
}

void RangerFusion::maxFusion() {
    laserSensorData = laserSensor->getData();
    radarLeftData = radarLeft->getData();
    radarRightData = radarRight->getData();

    double sData1, sData2, sData3, max;
    for (int i = 0; i < ARRAYSIZE; i++) {
        sData1 = *laserSensorData++;
        sData2 = *radarLeftData++;
        sData3 = *radarRightData++;

        max = 0.0;
        if (sData1 != (-1.0)) {
            max = sData1;
        }
        if (sData2 != (-1.0)) {
            if (max < sData2) {
                max = sData2;
            }
        }

        if (sData3 != (-1.0)) {
            if (max < sData3) {
                max = sData3;
            }
        }
        fusedData[i] = max;
    }
}

void RangerFusion::minFusion() {
    laserSensorData = laserSensor->getData();
    radarLeftData = radarLeft->getData();
    radarRightData = radarRight->getData();

    double sData1, sData2, sData3, min;
    bool check1 = false;
    bool check2 = false;
    bool check3 = false;


    for (int i = 0; i < ARRAYSIZE; i++) {
        sData1 = *laserSensorData++;
        sData2 = *radarLeftData++;
        sData3 = *radarRightData++;

        min = 100;

        if (sData1 != (-1.0)) {
            min = sData1;
        }
        if (sData2 != (-1.0)) {
            if (min > sData2) {
                min = sData2;
            }
        }

        if (sData3 != (-1.0)) {
            if (min > sData3) {
                min = sData3;
            }
        }
        if (min != 100) {
            fusedData[i] = min;
        } else {
            fusedData[i] = false;
        }
    }
}

void RangerFusion::averageFusion() {
    laserSensorData = laserSensor->getData();
    radarLeftData = radarLeft->getData();
    radarRightData = radarRight->getData();

    double sData1, sData2, sData3;
    double average = 0;
    int total = 0;
    bool check1 = false;
    bool check2 = false;
    bool check3 = false;
    for (int i = 0; i < ARRAYSIZE; i++) {
        sData1 = *laserSensorData++;
        sData2 = *radarLeftData++;
        sData3 = *radarRightData++;
        if (sData1 != (-1.0)) {
            average += sData1;
            total++;
        }
        if (sData2 != (-1.0)) {
            average += sData2;
            total++;
        }
        if (sData3 != (-1.0)) {
            average += sData3;
            total++;
        }
        if (average > 0) {
            fusedData[i] = (average / total);
        } else {
            fusedData[i] = 0.0;
        }
        average = 0;
        total = 0;

    }
}

double* RangerFusion::getData() {
    return fusedData;
}