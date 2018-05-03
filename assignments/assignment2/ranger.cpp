/* ranger.cpp
 * Programming for Mechatronic systems
 * Assignment 2
 *
 * @author: Jamin Early 99133391
 * @date: Week 5-7 Autumn Semester 2018
 */

#include "ranger.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <random>
#include <iostream>
#include <tgmath.h>

using namespace std;

Ranger::Ranger(){
}

// Sets X Offset. Returns if sane
bool Ranger::setXOffset(double i){
	if (i <= 1000 && i >= -1000) {
		xOffset_ = i;
		return true;
	}
	else {
		return false;
	}
}

// Returns X Offset
double Ranger::getXOffset(){
	return xOffset_;
}

// Sets Orientation offset. Returns if sane
bool Ranger::setOOffset(double i){
	if (i >= -180 && i <= 180) {
		oOffset_ = i;
		return true;
	}
	else{
		return false;
	}
}

// Returns Orientation offset
double Ranger::getOOffset(){
	return oOffset_;
}

// Sets baud rate. Returns if sane
bool Ranger::setBaudRate(int i){
	if (i == 38400 || i == 115200) {
		baudRate_ = i;
		return true;
	}
	else {
		return false;
	}
}

// Returns baud rate
int Ranger::getBaudRate(){
	return baudRate_;
}

// Sets port. Returns if sane
bool Ranger::setTtyACM(int i){
	if (i == 0 || i == 1 || i == 2) {
		ttyACM_ = i;
		return true;
	}
	else{
		return false;
	}
}

// Returns port
int Ranger::getTty(){
	return ttyACM_;
}

// Sets field of view. Returns if sane
bool Ranger::setFov(double i){
	if (i >= 0) {
		fov_ = i;
		return true;
	}
	else{
		return false;
	}
}

// Returns field of view
double Ranger::getFov(){
	return fov_;
}

// Sets minimum distance. Returns if sane
bool Ranger::setMinDistance(double i){
	if (i >= 0) {
		minDist_ = i;
		return true;
	}
	else {
		return false;
	}
}

// Returns minimum distance
double Ranger::getMinDistance(){
	return minDist_;
}

// Sets maximum distance. Returns if sane
bool Ranger::setMaxDistance(double i){
	if (i > 0) {
		maxDist_ = i;
		return true;
	}
	else {
		return false;
	}
}

// Returns maximum distance
double Ranger::getMaxDistance(){
	return maxDist_;
}

// Sets angular resolution. Returns if sane
bool Ranger::setAngularRes(double i){
	if (i > 0) {
		res_ = i;
		return true;
	}
	else{
		return false;
	}
}

// Returns angular resolution
double Ranger::getAngularRes(){
	return res_;
}

// Takes a reading and stores it in the scan vector.
void Ranger::takeReading(){
	// Ensure that the scan vector is clear
	scan_.clear();
	// Generate a seed
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	normal_distribution<double> distribution(6.0,5.0);
	// Populate scan vector with n number of 'readings' where n is field of view / angular resolution
	for (int i = 1; i <= (fov_/res_); i++) {
		// Generate a random value defined by the above normal distribution
		double reading = distribution(generator);
		// Continuously generate readings until it falls between the minimum and maximum distance
		while(reading < getMinDistance() || reading > getMaxDistance()) {
			reading = distribution(generator);
		}
		// Add reading to scan vector
		scan_.push_back(reading);
	}
}

// Returns the reading at a specific angle
double Ranger::readingAtAngle(double angle){
	// Checks if the angle is within range. Returns -1 if it is not (-1 was chosen as in this situation distance is an absolute value)
	if (angle >= fov_ + oOffset_ || angle < oOffset_) return -1;
	// Generate angle relative to the sensor
	double relativeAngle = angle - oOffset_;
	// Choose 'sector' that the angle falls in
	double sector = relativeAngle/res_;
	// Round the sector down to the closest integer and return the reading for that angle
	return scan_[floor(sector)];
}

// Takes a reading then returns it
vector<double> Ranger::getRawScan(){
	takeReading();
	return scan_;
}
