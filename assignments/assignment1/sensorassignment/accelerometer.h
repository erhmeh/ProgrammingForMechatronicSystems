/* accelerometer.h
 * Programming for Mechatronic systems
 * Assignment 1
 *
 * @author: Jamin Early 99133391
 * @date: Week 3 Autumn Semester 2018
 */

// Accelerometer class
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

// all of the member variables as well as the setters for the static values are set to private
private:
void setUSB();
void setSampleTime();
void setResolution();
long long int lastReading_;
int baud_;
int resolution_;
int maxAcceleration_;
int tty_;
int sampleTime_;
double xRaw_, yRaw_, zRaw_;
double xConv_, yConv_, zConv_;
};
