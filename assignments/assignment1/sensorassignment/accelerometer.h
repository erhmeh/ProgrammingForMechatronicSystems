/* accelerometer.h
 * Programming for Mechatronic systems
 * Assignment 1
 *
 * @author: Jamin Early 99133391
 * @date: Week 3 Autumn Semester 2018
 */

class Accelerometer {
public:
  Accelerometer();
  bool setBaud(int i);
  int getBaud();
  int getUSB();
  bool setMaxAcceleration(int i);
  int getMaxAcceleration();
  int getSampleTime();
  int getResolution();
  void takeSample();
  void convSample();
  void setupFixed();
  double getX();
  double getY();
  double getZ();
private:
  void setUSB();
  void setSampleTime();
  void setResolution();
  int baud_;
  int resolution_;
  int maxAcceleration_;
  int tty_;
  int sampleTime_;
  double xRaw_, yRaw_, zRaw_;
  double xConv_, yConv_, zConv_;
};
