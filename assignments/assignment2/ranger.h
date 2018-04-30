/* ranger.h
 * Programming for Mechatronic systems
 * Assignment 2
 *
 * @author: Jamin Early 99133391
 * @date: Week 5-7 Autumn Semester 2018
 */



#ifndef RANGER_H
#define RANGER_H

#include <vector>

using namespace std;

class Ranger{
public:
  Ranger();
  bool setXOffset(double i);
  double getXOffset();
  bool setOOffset(double i);
  double getOOffset();
  bool setNumOfSamples(int i);
  int getNumOfSamples();
  bool setBaudRate(int i);
  int getBaudRate();
  bool setTtyACM(int i);
  int getTty();
  bool setAngularRes(double i);
  double getAngularRes();
  double getFov();
  double getMinDistance();
  double getMaxDistance();
  double readingAtAngle(double angle);
  void takeReading();
  vector<double> getRawScan();
protected:
  double xOffset_;
  double oOffset_;
  bool setFov(double i);
  double fov_;
  bool setRes(double i);
  double res_;
  int numOfSamples_;
  bool setMinDistance(double i);
  double minDist_;
  bool setMaxDistance(double i);
  double maxDist_;
  int baudRate_;
  int ttyACM_;
  vector<double> scan;
};

#endif
