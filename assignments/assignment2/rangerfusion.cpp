/* rangerfusion.cpp
 * Programming for Mechatronic systems
 * Assignment 2
 *
 * @author: Jamin Early 99133391
 * @date: Week 5-7 Autumn Semester 2018
 */

#include <iostream>
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "ranger.h"
#include "rangerfusion.h"
#include "rangerfusioninterface.h"

using namespace std;

// Setter for the rangerFusion class, accepting an array of Ranger pointers
void RangerFusion::setRangers(vector<Ranger *> sensor){
	rangers_ = sensor;
}

// Returns a vector of fused ranger data
vector<double> RangerFusion::getFusedRangeData(){
	// Clear the vector, otherwise it may have undefined or old data in it.
	fusedData_.clear();
	// Iterate through each value of each of the rawData_ vectors
	for(int i = 0; i < 18; i++) {
		// If user requests the Maximum reading
		if (requestedFuseType_ == 'U') {
			// Set temp to an imposible value
			double temp = -1;
			// Iterate through each reading's value at the matching angle
			for(int j = 0; j < rawData_.size(); j++) {
				// If the value is greater than the previous maximum, replace the value. Ignore if impossible value.
				if(rawData_.at(j).at(i) > temp && rawData_.at(j).at(i) != -1) {
					temp = rawData_.at(j).at(i);
				}
			}
			// Push the maximum value to fusedData_
			fusedData_.push_back(temp);
		}
		// If the user requests the Minimum reading
		if (requestedFuseType_ == 'L') {
			// Set temp to an imposible value
			double temp = 1000.0;
			// Iterate through each reading's value at the matching angle
			for(int j = 0; j < rawData_.size(); j++) {
				// If the value is less than the previous minimum, replace the value. Ignore if impossible value.
				if(rawData_.at(j).at(i) < temp && rawData_.at(j).at(i) != -1) {
					temp = rawData_.at(j).at(i);
				}
			}
			// Push the minimum value to fusedData_
			fusedData_.push_back(temp);
		}
		// If user requests the Average reading
		if (requestedFuseType_ == 'A') {
			// Set temp to 0
			double temp = 0;
			// Set counter to 0
			double counter = 0;
			// Iterate through each reading's value at the matching angle
			for(int j = 0; j < rawData_.size(); j++) {
				// Ignore if imposible value
				if(rawData_.at(j).at(i) != -1) {
					// Add value to temp
					temp+=rawData_.at(j).at(i);
					// Increment counter
					counter++;
				}
			}
			// Divide temp by counter and push value to fusedData_
			fusedData_.push_back(temp/counter);
		}
	}
	// Return fusedData_
	return fusedData_;
}

// Returns a vector of vectors of raw ranger readings
vector<vector<double> > RangerFusion::getRawRangeData(){
	// Clear the rawData_ vector as it may have undefined or old data in it.
	rawData_.clear();
	// Iterate through each vector
	for (int i = 0; i < rangers_.size(); i++) {
		// Create ranger pointer
		Ranger *r = rangers_.at(i);
		// Tell ranger to take a reading
		r->takeReading();
		// Create temporary vector
		vector<double> temp;
		// Populate vector with angle specific values (every 10 degrees)
		for (int j = 0; j < 18; j++) {
			temp.push_back(r->readingAtAngle(j*10));
		}
		// Push temp vector onto rawData_
		rawData_.push_back(temp);
	}
	// Return rawData_
	return rawData_;
}
