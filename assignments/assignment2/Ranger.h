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
  bool setOOffset(double i);
  bool setNumOfSamples(int i);
  bool setBaudRate(int i);
  bool setTtyACM(int i);
protected:
  bool setXOffset(double i, int min, int max);
  double xOffset;
  double oOffset;
  double fov;
  double res;
  int numOfSamples;
  double minDist;
  double maxDist;
  int baudRate;
  int ttyACM;
};

#endif
