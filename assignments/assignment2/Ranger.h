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
  bool setXOffset(double i);
  bool setOOffset(double i);
  bool setFov(double i);
  bool setRes(double i);
  bool setNumOfSamples(int i);
  double getData();
  bool setTtyUSB();
private:
  double xOffset;
  double oOffset;
  double fov;
  double res;
  int numOfSamples;
  double data;
  int ttyUSB;
};

#endif
