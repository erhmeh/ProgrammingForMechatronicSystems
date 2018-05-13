#include "ranger.h"
#include <iostream>

Ranger::Ranger() {
    model = (char*) "UNSPECIFIED";
}

char* Ranger::getModel() {
    return model;
}

int Ranger::getBaudRate() {
    return baudRate;
}

int Ranger::getPort() {
    return port;
}

int Ranger::getFOV() {
    return FOV;
}

double Ranger::getMaxDist() {
    return maxDistance;
}

double Ranger::getMinDist() {
    return minDistance;
}

int Ranger::getSamples() {
    return samples;
}

double* Ranger::getData() {
    return data;
}

//setting the boolean conditions
//compares the user's input to available baud rate options, sets the value if correct. Otherwise will default to a set value

bool Ranger::setBaudRate(int baudInput) {
    if (baudInput == BAUDRATE_1 || baudInput == BAUDRATE_2) {
        baudRate = baudInput;
        return true;
    } else {
        cin.clear(); //ensure to use default values if char input instead of integer, applied to other setters
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input is invalid - defaulting to: " << BAUDRATE_1 << endl;
    }
}

//compares the user's input to available port options, sets the value if correct. Otherwise will default to a set value

bool Ranger::setPort(int portInput) {
    if (portInput == PORT_0 || portInput == PORT_1 || portInput == PORT_2) {
        port = portInput;
        return true;
    } else {
        cin.clear(); //ensure to use default values if char input instead of integer, applied to other setters
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input is invalid - defaulting to: " << PORT_0 << endl;
    }
}

//generates a number that is within the ranger's range and uses the specifics for mean and standard deviation

double Ranger::distGenerator() {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::normal_distribution<double>distribution(MEAN, STD);
    double generatedValue;
    while (1);
    {
        generatedValue = distribution(generator);
        if ((generatedValue >= MINRADAR) && (generatedValue <= MAXRADAR)) {
            return generatedValue;
        }
    }
}