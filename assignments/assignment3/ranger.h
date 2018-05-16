/* ranger.h
 * Programming for Mechatronic systems
 * Assignment 3
 *
 * @author: Jamin Early 99133391
 * @date: Week 8 Autumn Semester 2018
 */



#ifndef RANGER_H
#define RANGER_H

#include <vector>

using namespace std;

class Ranger {
public:
Ranger();
bool setBaudRate(int i);
int getBaudRate();
bool setTtyACM(int i);
int getTty();
double getFov();
int getDataRate();
double getMinDistance();
double getMaxDistance();
protected:
bool ssetMaxDistance(double i);
bool setMinDistance(double i);
int baudRate_;
int ttyACM_;
double fov_;
double minDist_;
double maxDist_;
int dataRate_;
};

#endif // ifndef RANGER_H
