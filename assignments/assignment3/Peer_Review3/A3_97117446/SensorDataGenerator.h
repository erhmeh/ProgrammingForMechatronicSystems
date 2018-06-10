#ifndef SENSORDATAGENERATOR_H
#define SENSORDATAGENERATOR_H

#include <vector>

// values that are constants to the class RandomNormalDistribution
const int DEFAULT_MEAN = 0;
const double DEFAULT_STDDEV = 0.1;
const int DEFAULT_NUMOFVALUES = 1; //Default Number Of Values = 1

/*!
 *  \ingroup   ac_shapre SensorDataGenerator
 *  \brief     SensorDataGenerator class
 *  \details
 *  This class is used by the Ranger class to generate virtual sensor data for sensors used in a range finder.\n
 *  \author    Jordan Henry
 *  \version   1.0
 *  \date      20/05/2018
 *  \pre       none
 *  \bug       none reported as of 20/05/2018
 *  \warning   none reported as of 20/05/2018
 */

class SensorDataGenerator {
public:
    // Constructor initialies the class object //
    SensorDataGenerator();

    // SensorDataGenerator (CLASS) Setters //
    /**
     * @brief setNumOfValues : sets the number of data readings required by the sensor
     * @param number
     */
    void setNumOfValues(int number); // sets the number of random numbers to be produced and sent back once getValues() is called

    // SensorDataGenerator (CLASS) Getters //
    /**
     * @brief getValues : allows the sensor to ask for the data readings
     * @param randomNums
     */
    void getValues(std::vector<double>& randomNums); // Sends the random numbers to the Ranger (BASE) class through passing by reference

protected:
    int _numOfValues; // Number of Random Numbers to be generated
    std::vector<double> _randomNums; // vector of stored Random Numbers generated

private:

    // Normal Distribution //
    /**
     * @brief normalDistribution : generates the random numbers within a normal distribution
     */
    void normalDistribution(); // Produces Random Numbers this is only used by other class methods

    int _mean; // Mean of Normal Distribution of Random Numbers
    int _stdDev; // Standard Deviation of Normal Distribution of Random Numbers
};

#endif // SENSORDATAGENERATOR_H
