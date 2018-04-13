/* Ranger.h
 * Programming for Mechatronic systems
 * Assignment 2
 *
 * @author: Jamin Early 99133391
 * @date: Week 5-7 Autumn Semester 2018
 */

#ifndef RANGER_H
#define RANGER_H

class Ranger{
public:
  Ranger();
  double getXOffset();
  double getOOffset();
  bool setNumOfSamples(int i);
  int getNumOfSamples();
  bool setBaudRate(int i);
  int getBaudRate();
  bool setTtyACM(int i);
  int getTty();
protected:
  bool setXOffset(double i, int min, int max);
  bool setOOffset(double i);
  double xOffset_;
  double oOffset_;
  bool setFov(double i);
  double fov_;
  bool setRes(double i);
  double res_;
  int numOfSamples_;
  double minDist_;
  double maxDist_;
  int baudRate_;
  int ttyACM_;
};

#endif
