#include <cstdio>
#include <iostream>
#include <unistd.h>
#include"ranger.h"
#include"laser.h"
#include"radarLeft.h"
#include"radarRight.h"
#include"rangerfusion.h"

unsigned int microseconds;
using namespace std;

#define NOSENSORS 3

int portArray[NOSENSORS] = {-1, -1, -1};
int lastEntry = 0;

bool portCheck(int port) {

    for (int i = 0; i < NOSENSORS; i++) {
        if (port == portArray[i]) {
            return false;
        }
    }
    portArray[lastEntry] = port;
    lastEntry++;
    return true;
}

void setBaudRate(Ranger* sensor) {
    printf("Setting baudrate of sensor: %s\n", sensor->getModel());
    bool check = false;
    int selection;
    while (!check) {
        printf("Enter 1 for: %d\n", BAUDRATE_1);
        printf("Enter 2 for: %d\n", BAUDRATE_2);
        cin >> selection;
        switch (selection) {
            case 1:
            {
                check = sensor->setBaudRate(BAUDRATE_1);
                printf("Selected baudrate is: %d\n", sensor->getBaudRate());
                break;
            }
            case 2:
            {
                check = sensor->setBaudRate(BAUDRATE_2);
                printf("Selected baudrate is: %d\n", sensor->getBaudRate());
                break;
            }
            default:
            {
                printf("Invalid Selection.\n");
                break;
            }
        }

    }
}

void setPort(Ranger* sensor) {
    printf("Setting port of sensor: %s\n", sensor->getModel());
    bool check = false;
    int selection;
    while (!check) {
        printf("Enter 1 for port %d\n", PORT_0);
        printf("Enter 2 for port %d\n", PORT_1);
        printf("Enter 3 for port %d\n", PORT_2);
        cin >> selection;
        switch (selection) {
            case 1:
            {
                if (portCheck(PORT_0)) {
                    check = sensor->setPort(PORT_0);
                    printf("%s is connected to /dev/tty/ACM%d \n", sensor->getModel(), sensor->getPort());
                } else {
                    printf("Port already in use, please pick another.\n");
                }
                break;
            }
            case 2:
            {
                if (portCheck(PORT_1)) {
                    check = sensor->setPort(PORT_1);
                    printf("%s is connected to /dev/tty/ACM%d \n", sensor->getModel(), sensor->getPort());
                } else {
                    printf("Port already in use, please pick another.\n");
                }
                break;
            }
            case 3:
            {
                if (portCheck(PORT_2)) {
                    check = sensor->setPort(PORT_2);
                    printf("%s is connected to /dev/tty/ACM%d \n", sensor->getModel(), sensor->getPort());
                } else {
                    printf("Port already in use, please pick another.\n");
                }
                break;
            }
            default:
            {
                printf("Invalid Selection.\n");
                break;
            }
        }

    }
}

void setAngularResolution(Laser* sensor) {
    printf("Setting angular resolution of sensor: %s\n", sensor->getModel());
    bool check = false;
    int selection;
    while (!check) {
        printf("Enter 1 for: %d\n", ANGLERES_1);
        printf("Enter 2 for: %d\n", ANGLERES_2);
        cin >> selection;
        switch (selection) {
            case 1:
            {
                check = sensor->setAngleRes(ANGLERES_1);
                printf("Selected angular resolution is: %d\n", sensor->getAngleRes());
                break;
            }
            case 2:
            {
                check = sensor->setAngleRes(ANGLERES_2);
                printf("Selected angular resolution is: %d\n", sensor->getAngleRes());
                break;
            }
            default:
            {
                printf("Invalid Selection.\n");
                break;
            }
        }

    }

}

void setFieldOfViewL(RadarLeft* sensor) {
    printf("Setting field of view for sensor: %s\n", sensor->getModel());
    bool check = false;
    int selection;
    while (!check) {
        printf("Enter 1 for: %d\n", RADARFOV_1);
        printf("Enter 2 for: %d\n", RADARFOV_2);
        cin >> selection;
        switch (selection) {
            case 1:
            {
                check = sensor->setFOV(RADARFOV_1);
                printf("Selected field of view is: %d\n", sensor->getFOV());
                break;
            }
            case 2:
            {
                check = sensor->setFOV(RADARFOV_2);
                printf("Selected field of view is: %d\n", sensor->getFOV());
                break;
            }
            default:
            {
                printf("Invalid Selection.\n");
                break;
            }
        }

    }
}

void setFieldOfViewR(RadarRight* sensor) {
    printf("Setting field of view for sensor: %s\n", sensor->getModel());
    bool check = false;
    int selection;
    while (!check) {
        printf("Enter 1 for: %d\n", RADARFOV_1);
        printf("Enter 2 for: %d\n", RADARFOV_2);
        cin >> selection;
        switch (selection) {
            case 1:
            {
                check = sensor->setFOV(RADARFOV_1);
                printf("Selected field of view is: %d\n", sensor->getFOV());
                break;
            }
            case 2:
            {
                check = sensor->setFOV(RADARFOV_2);
                printf("Selected field of view is: %d\n", sensor->getFOV());
                break;
            }
            default:
            {
                printf("Invalid Selection.\n");
                break;
            }
        }

    }
}

void selectFusionMethod(RangerFusion* fuse) {
    printf("Setting fusion method\n");
    bool check = false;
    int selection;
    double *fusedData;
    while (!check) {
        printf("Enter 1 for min method\n");
        printf("Enter 2 for max method\n");
        printf("Enter 3 for average method\n");
        cin >> selection;
        switch (selection) {
            case 1:
            {
                printf("Min method selected\n");
                while (1) {
                    fuse->minFusion();
                    fusedData = fuse->getData();
                    for (int i = 0; i < ARRAYSIZE; i++) {
                        printf("Minimum value: %f\n", *fusedData++);
                    }

                }
                break;
            }
            case 2:
            {
                printf("Max method selected, waiting 3 seconds \n");
                while (1) {
                    fuse->maxFusion();
                    fusedData = fuse->getData();
                    for (int i = 0; i < ARRAYSIZE; i++) {
                        printf("Maximum value: %f\n", *fusedData++);
                    }
                }
                break;
            }
            case 3:
            {
                printf("Average method selected, waiting 3 seconds \n");
                //sleep(3);
                while (1) {
                    fuse->averageFusion();
                    fusedData = fuse->getData();
                    for (int i = 0; i < ARRAYSIZE; i++) {
                        printf("Average value: %f\n", *fusedData++);
                    }
                }
            }

            default:
            {
                printf("Invalid Selection.\n");
                break;
            }
        }

    }

}

void displaySensor(Ranger *ranger) {
    printf("DISPLAYING PARAMETERS FOR SESNOR: %s\n", ranger->getModel());
    printf("BAUDRATE: %d\n", ranger->getBaudRate());
    printf("PORT: %d\n", ranger->getPort());
    printf("FIED OF VIEW: %d\n", ranger->getFOV());
    printf("MAX DISTANCE: %f\n", ranger->getMaxDist());
    printf("MIN DISTANCE: %f\n", ranger->getMinDist());
}

int main() {
    Laser laser;
    RadarLeft radar_1;
    RadarRight radar_2;
    RangerFusion fusion;

    displaySensor(&laser);
    printf("ANGULAR RESOLUTION: %d\n\n", laser.getAngleRes());
    setPort(&laser);
    setBaudRate(&laser);
    setAngularResolution(&laser);

    printf("\n\n\n");

    displaySensor(&radar_1);
    printf("\n");
    setPort(&radar_1);
    setBaudRate(&radar_1);
    setFieldOfViewL(&radar_1);

    printf("\n\n\n");

    displaySensor(&radar_2);
    printf("\n");
    setPort(&radar_2);
    setBaudRate(&radar_2);
    setFieldOfViewR(&radar_2);

    printf("\n\n\n");

    Ranger * rangers[NOSENSORS] = {&laser, &radar_1, &radar_2};

    fusion.getRangers(rangers);

    selectFusionMethod(&fusion);

    return 0;
}
