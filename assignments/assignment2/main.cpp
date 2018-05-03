/* main.cpp
 * Programming for Mechatronic systems
 * Assignment 2
 *
 * @author: Jamin Early 99133391
 * @date: Week 5-7 Autumn Semester 2018
 */

#include <iostream>
#include <vector>
#include <thread>
#include "ranger.h"
#include "radar.h"
#include "laser.h"
#include "rangerfusion.h"
#include <chrono>
using namespace std;

// A for Average, U for Maximum, L for Minimum
char requestedFuseType = 'A';

// All of the user configurable values
#define UPDATE_RATE       1             //Amount of seconds to wait between updates

#define LASER_BAUD        38400
#define LASER_XOFFSET     0
#define LASER_OOFFSET     0
#define LASER_TTY         2
#define LASER_ANGULAR_RES 30

#define RADAR1_BAUD       38400
#define RADAR1_XOFFSET    0
#define RADAR1_OOFFSET    0
#define RADAR1_TTY        1

#define RADAR2_BAUD       115200
#define RADAR2_XOFFSET    0
#define RADAR2_OOFFSET    0
#define RADAR2_TTY        0


// Decleration of objects
Laser laser;
Radar radar1;
Radar radar2;
RangerFusion fuser;

// Placeholder functions
void startSensors();
void initLaser();
void initRadar1();
void initRadar2();
void printRawData();
void printFusedData();

// Calls the init function for the laser and two radars
void startSensors()
{
	initLaser();
	initRadar1();
	initRadar2();
}

// Prints the default values and configures user defined values for the laser.
void initLaser()
{
	cout << "Initialising laser. Fixed Parameters are as follows." << endl;
	cout << "Model Number: UTM-XXL" << endl;
	cout << "FOV: " << laser.getFov() << endl;
	cout << "Min distance: " << laser.getMinDistance() << endl;
	cout << "Max distance: " << laser.getMaxDistance() << endl << endl;
	cout << "Configuring user defined variables:" << endl;
	Laser();
	if (laser.setBaudRate(LASER_BAUD))
	{
		cout << "Baud Rate set: " << laser.getBaudRate() << endl;
	}
	else
	{
		cout << "Invalid baud rate. Default value used: " << laser.getBaudRate() << endl;
	}
	if (laser.setXOffset(LASER_XOFFSET))
	{
		cout << "X offset set: " << laser.getXOffset() << endl;
	}
	else
	{
		cout << "Invalid offset. Default value used: " << laser.getXOffset() << endl;
	}
	if (laser.setOOffset(LASER_OOFFSET))
	{
		cout << "Orientation offset set: " << laser.getOOffset() << endl;
	}
	else
	{
		cout << "Invalid orientation offset. Default value used: " << laser.getOOffset() << endl;
	}
	if (radar1.getTty() != LASER_TTY && radar2.getTty() != LASER_TTY && laser.setTtyACM(LASER_TTY))
	{
		cout << "Laser has been attached as ttyACM" << LASER_TTY << endl;
	}
	else
	{
		if (radar1.getTty() == 0 || radar2.getTty() == 0)
		{
			if (radar1.getTty() == 1 || radar2.getTty() == 1)
			{
				laser.setTtyACM(2);
				cout << "Laser has been attached to ttyACM2" << endl;
			}
			else
			{
				laser.setTtyACM(1);
				cout << "Laser has been attached to ttyACM1" << endl;
			}
		}
		else
		{
			laser.setTtyACM(0);
			cout << "Laser has been attached to ttyACM0" << endl;
		}
	}
	if (laser.setAngularRes(LASER_ANGULAR_RES))
	{
		cout << "Angular Resolution set: " << laser.getAngularRes() << endl << endl;
	}
	else
	{
		cout << "Invalid Angular Resolution. Default value used: " << laser.getAngularRes() << endl << endl;
	}
}

// Prints the default values and configures user defined values for radar 1.
void initRadar1()
{
	cout << "Initialising Radar 1. Fixed Parameters are as follows." << endl;
	cout << "Model Number: RAD-001" << endl;
	cout << "FOV: " << radar1.getFov() << endl;
	cout << "Angular Resolution: " << radar1.getAngularRes() << endl;
	cout << "Min distance: " << radar1.getMinDistance() << endl;
	cout << "Max distance: " << radar1.getMaxDistance() << endl << endl;
	cout << "Configuring user defined variables:" << endl;
	if (radar1.setBaudRate(RADAR1_BAUD))
	{
		cout << "Baud Rate set: " << radar1.getBaudRate() << endl;
	}
	else
	{
		cout << "Invalid baud rate. Default value used: " << radar1.getBaudRate() << endl;
	}
	if (radar1.setXOffset(RADAR1_XOFFSET))
	{
		cout << "X offset set: " << radar1.getXOffset() << endl;
	}
	else
	{
		cout << "Invalid offset. Default value used: " << radar1.getXOffset() << endl;
	}
	if (radar1.setOOffset(RADAR1_OOFFSET))
	{
		cout << "Orientation offset set: " << radar1.getOOffset() << endl;
	}
	else
	{
		cout << "Invalid orientation offset. Default value used: " << radar1.getOOffset() << endl;
	}
	if (laser.getTty() != RADAR1_TTY && radar2.getTty() != RADAR1_TTY && radar1.setTtyACM(RADAR1_TTY))
	{
		cout << "Radar 1 has been attached as ttyACM" << RADAR1_TTY << endl << endl;
	}
	else
	{
		if (laser.getTty() == 0 || radar2.getTty() == 0)
		{
			if (laser.getTty() == 1 || radar2.getTty() == 1)
			{
				radar1.setTtyACM(2);
				cout << "Radar 1 has been attached to ttyACM2" << endl << endl;
			}
			else
			{
				radar1.setTtyACM(1);
				cout << "Radar 1 has been attached to ttyACM1" << endl << endl;
			}
		}
		else
		{
			radar1.setTtyACM(0);
			cout << "Radar 1 has been attached to ttyACM0" << endl << endl;
		}
	}
}

// Prints the default values and configures user defined values for radar 2.
void initRadar2()
{
	cout << "Initialising Radar 2. Fixed Parameters are as follows." << endl;
	cout << "Model Number: RAD-001" << endl;
	cout << "FOV: " << radar2.getFov() << endl;
	cout << "Angular Resolution: " << radar2.getAngularRes() << endl;
	cout << "Min distance: " << radar2.getMinDistance() << endl;
	cout << "Max distance: " << radar2.getMaxDistance() << endl << endl;
	cout << "Configuring user defined variables:" << endl;
	if (radar2.setBaudRate(RADAR2_BAUD))
	{
		cout << "Baud Rate set: " << radar2.getBaudRate() << endl;
	}
	else
	{
		cout << "Invalid baud rate. Default value used: " << radar2.getBaudRate() << endl;
	}
	if (radar2.setXOffset(RADAR2_XOFFSET))
	{
		cout << "X offset set: " << radar2.getXOffset() << endl;
	}
	else
	{
		cout << "Invalid offset. Default value used: " << radar2.getXOffset() << endl;
	}
	if (radar2.setOOffset(RADAR2_OOFFSET))
	{
		cout << "Orientation offset set: " << radar2.getOOffset() << endl;
	}
	else
	{
		cout << "Invalid orientation offset. Default value used: " << radar2.getOOffset() << endl;
	}
	if (laser.getTty() != RADAR2_TTY && radar1.getTty() != RADAR2_TTY && radar2.setTtyACM(RADAR1_TTY))
	{
		cout << "Radar 2 has been attached as ttyACM" << RADAR2_TTY << endl << endl;
	}
	else
	{
		if (laser.getTty() == 0 || radar1.getTty() == 0)
		{
			if (laser.getTty() == 1 || radar1.getTty() == 1)
			{
				radar1.setTtyACM(2);
				cout << "Radar 2 has been attached to ttyACM2" << endl << endl;
			}
			else
			{
				radar2.setTtyACM(1);
				cout << "Radar 2 has been attached to ttyACM1" << endl << endl;
			}
		}
		else
		{
			radar2.setTtyACM(0);
			cout << "Radar 2 has been attached to ttyACM0" << endl << endl;
		}
	}
}

// Prints out the fused data in a readable manner
void printFusedData()
{
	cout << "Displaying fused data: " << endl;
	// Generate a vector of fused data
	vector<double> fusedData = fuser.getFusedRangeData();
	// Iterate through the vector and print out the value at every 10°
	for (int i = 0; i != fusedData.size(); i++) {
		cout << i*10 << "° - "<< (int) ((i*10) + 10) << "°: " << fusedData.at(i) << endl;
	}
	cout << endl;
}

// Prints the raw sensor data to the console in a readable manner.
void printRawData()
{
	cout << "Displaying raw data: " << endl;
	// Obtain a vector of a vector holding the raw readings of each sensor
	vector<vector <double> > rawData = fuser.getRawRangeData();
	// Iterate through each vector and print the results every 10°
	for (int j = 0; j < rawData.size(); j++) {
		cout << "Sensor " << j << endl;
		for (int i = 0; i < 18; i++) {
			cout << i*10 << "° - "<< (int) ((i*10) + 10) << "°: " << rawData.at(j).at(i) << endl;
		}
		cout << endl;
	}
}

int main()
{
	// Initialisation
	startSensors();
	// Take a reading
	radar1.takeReading();
	radar2.takeReading();
	laser.takeReading();

	// Set the rangers
	fuser.setRangers({&laser, &radar1, &radar2});
	// Parse the requested fusing method to the rangerfusion class
	fuser.requestedFuseType_ = requestedFuseType;
	// Loop forever
	while(true) {
		// Take a reading
		fuser.getRawRangeData();
		// Call the printFusionData() method
		printFusedData();
		// Updates the displayed results as defined above
		std::this_thread::sleep_for (std::chrono::seconds(UPDATE_RATE));
	}
	return 0;
}
