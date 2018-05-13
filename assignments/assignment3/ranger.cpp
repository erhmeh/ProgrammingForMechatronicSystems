/* ranger.cpp
 * Programming for Mechatronic systems
 * Assignment 3
 *
 * @author: Jamin Early 99133391
 * @date: Week 8 Autumn Semester 2018
 */

#include "ranger.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <random>
#include <iostream>
#include <tgmath.h>

Ranger::Ranger(){
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
